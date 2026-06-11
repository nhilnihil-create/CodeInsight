#include <iostream>
#include <string>
using namespace std;

int number;
string s;

int main(){
	cin>>s;
	for(int i=0;i<=3;i++){
		if(s[i]=='+'){
			number++;
		}else{
			number--;
		}
	}cout<<number<<endl;
}