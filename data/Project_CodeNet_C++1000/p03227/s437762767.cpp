#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	string out = "";
	if (s.length() == 3) {
		out.push_back(s[2]);
		out.push_back(s[1]);
		out.push_back(s[0]);
	} else {
		out = s;
	}
	cout << out << endl;
	return 0;
}