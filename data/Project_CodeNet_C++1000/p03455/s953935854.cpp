#include<iostream>
#include<string>
using namespace std;

int main() {
	int a,b;
	string r;

	cin >> a >> b;
	
	r = a%2==0 || b%2==0 ? "Even" : "Odd";
	cout << r << endl;
}