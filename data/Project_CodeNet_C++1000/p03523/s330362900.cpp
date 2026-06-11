#include <iostream>
#include <cstdio>
#include <regex>
using namespace std;

string s;
int main() {
	cin >> s;
	cout << (regex_match(s, regex("A?KIHA?BA?RA?")) ? "YES" : "NO");
	return 0;
}