#include <iostream>
#include <cstdio>
using namespace std;

char a, b;
int main() {
	cin >> a >> b;
	cout << (a==b ? '=' : a>b ? '>' : '<');
	return 0;
}