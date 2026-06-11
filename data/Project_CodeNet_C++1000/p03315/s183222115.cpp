#include <iostream>
#include <cstdio>
using namespace std;

int c;
string s;
int main() {
	cin >> s;
	for(int i=0; s[i]; i++) s[i]=='+' ? c++ : c--;
	cout << c;
	return 0;
}
