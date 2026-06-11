#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	regex pt("\\.*A?KIHA?BA?RA?\\.*");
	cout << (regex_match(s, pt) ? "YES" : "NO") << endl;
	return 0;
}