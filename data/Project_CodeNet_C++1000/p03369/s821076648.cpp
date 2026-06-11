#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	int a = 700;
	cin >> s;
	if (s[0] == 'o') a = a + 100;
	if (s[1] == 'o') a = a + 100 ;
	if (s[2] == 'o') a = a + 100;

	cout << a << endl;

	return 0;
 }