#include<iostream>
#include<string>

using namespace std;

int main(){
	int  a = 0 , b = 0 ;
	string l1;
	cin >> l1;
	while (a != 3){
		if (l1[a] == '1')
			b++;
	a++;}
cout << b;
}