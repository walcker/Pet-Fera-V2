#include <iostream>

#include "veterinario.hpp"
#include "tratador.hpp"
#include "animal.hpp"

using namespace std;

void pausar() {
#if defined _WIN32
    system("pause");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"");
#elif defined (__APPLE__)
    system("read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"");
#endif
}
void limpaTela()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void menuPrincipal(Animal* an, Veterinario* vt) {
	char opcao;
	limpaTela();
	do {	 
		cout<< endl << "Opções: ";
		cout<< endl << "========";
		cout<< endl << "1 - Cadastrar um animal.";
    cout<< endl << "2 - Listar animais.";
		cout<< endl << "3 - Cadastrar um veterinário.";
    cout<< endl << "4 - Listar veterinários.";
		cout<< endl << "---------";
		cout<< endl << endl << "X - Encerrar.";

		cout<< endl << endl << "Selecione a opção: ";

		cin >> opcao;

		limpaTela();
		 
		switch(opcao)
		{
			case '1' :{ an->criarAnimal();}
			break;
      case '2' :{ an->listarAnimal();}
			break;
			case '3' :{ vt->criarVeterinario();}
			break;
      case '4' :{ vt->listarVeterinario();}
			break;
			case 'X' :
			case 'x' :{ return;}
			break;
			default : cout << endl << "Opção inválida!";
		}
		cout << endl;

		pausar();
		limpaTela();
	
	} while (opcao != 'X' && opcao !='x');
}

void 
Animal::criarAnimal() {
  string nome;
	string classe;
  string especie;
  string sexo;
  string habitat;
  string extincao;

  cout << "Nome: " << endl;
  cin >> nome;
  cout << "Classe: " << endl;
  cin >> classe;
  cout << "Especie: " << endl;
  cin >> especie;
  cout << "Sexo: " << endl;
  cin >> sexo;
  cout << "Habitat: " << endl;
  cin >> habitat;
  cout << "Extinção: " << endl;
  cin >> extincao;
}
void Animal::listarAnimal() {
		cout << nome << endl;
    cout << classe << endl;
    cout << especie << endl;
    cout << sexo << endl;
    cout << habitat << endl;
    cout << extincao << endl;
    cout << " " << endl;
    pausar();
}

void 
Veterinario::criarVeterinario() {
  string nome;
	string crmv;
  string data;
  
  cout << "Nome: " << endl;
  cin >> nome;
  cout << "CRMV: " << endl;
  cin >> crmv;
  cout << "Data: " << endl;
  cin >> data;
}
void Veterinario::listarVeterinario() {
		cout << nome << endl;
    cout << crmv << endl;
    cout << data << endl;
    cout << " " << endl;
    pausar();
}

int main(int argc, char const *argv[]){
 
  Animal an("Vermelhinha","Mamífero","Capivara", "Fêmea", "Nativo", "Em extinção");

  cout << " " << endl;
  cout << "Nome: " << an.getNome() << endl;
  cout << "Classe: " << an.getClasse() << endl;
  cout << "Espécie: " << an.getEspecie() << endl;
  cout << "Sexo: " << an.getSexo() << endl;
  cout << "Habitat: " << an.getHabitat() << endl;
  cout << "Situação: " << an.getExtincao() << endl;
  
  Veterinario vt("José da Veiga","5648-9","03/05/1990");

  cout << " " << endl;
  cout << "Nome: " << vt.getNome() << endl;
  cout << "CRMV: " << vt.getCrmv() << endl;
  cout << "Data de contatação: " << vt.getData() << endl;

  Tratador tr("Johny Silverhand","Azul","23/10/2013");

  cout << " " << endl;
  cout << "Nome: " << tr.getNome() << endl;
  cout << "CRMV: " << tr.getCor() << endl;
  cout << "Data de contatação: " << tr.getData() << endl;

  
	return 0;
}


/*Classes: Funcionario, Tratador, Veterinario, Animal, Anfíbio, Reptil, Ave, Mamífero, Silvestre (opicional), Nativo, Exotico, Domestico (necessário ???), AnfíbioNativo, AnfíbioExotico ... (repete para cada classe de Animal)...*/