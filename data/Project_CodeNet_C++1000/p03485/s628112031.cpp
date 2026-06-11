#include<iostream>
#include<string>

using namespace std;

int main(){
	float a , b , f ;
	int c , d ;
	cin >> a;
	cin >> b;
	c = a;
	d = b;
	if (((a+b)/2)-((c + d)/2) >= ((((c + d)/2)+1)-((a+b)/2))){
		cout << ((c + d)/2)+1;}
	if (((a+b)/2)-((c + d)/2) < ((((c + d)/2)+1)-((a+b)/2))){
		cout << ((c + d)/2);}
}