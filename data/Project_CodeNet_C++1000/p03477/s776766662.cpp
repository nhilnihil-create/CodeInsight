#include<iostream>
#include<string>

using namespace std;

int main(){
	int a , b , c , d;
	cin >> a >> b >> c >> d;
	if (a+b > c+d)
		cout << "Left";
	if (a+b <c+d)
		cout << "Right";
	if (a+b == c+d)
		cout << "Balanced";
}