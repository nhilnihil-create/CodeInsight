#include<string>
#include<iostream>
using namespace std;

int main() {
	int s;
	cin >> s;
	
	int a=0;

	s >= 100 ? a += 1 : a += 0;
	s-100 >= 10 ? a += 1 : a += 0;
	s >= 10 && s <= 11 ? a += 1 : a += 0;
	s - 110 == 1 ? a += 1 : a += 0;
	s - 100 == 1 ? a += 1 : a += 0;
	s - 10 == 1 ? a += 1 : a += 0;
	s == 1 ? a += 1 : a += 0;
	cout << a << endl;

}