#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <locale>
using namespace std;
int main(){

	
	char X,Y;

	cin>> X>> Y;
	if(int(X) > int(Y)){
		
		cout<<">";
	}else if(int(X) < int(Y)){
		cout<<"<";
	}else{
		cout<<"=";
	}
	
	return 0;
}