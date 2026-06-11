#include <iostream>
#include <cstdio>
using namespace std;

string s;
int main() {
	cin >> s;
	cout << (((s[0]=='o') + (s[1]=='o') + (s[2]=='o')) * 100 + 700);
	return 0;
}
