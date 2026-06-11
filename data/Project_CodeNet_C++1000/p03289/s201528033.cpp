#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool ans = true;
	if (s.at(0) != 'A')ans = false;
	if (!('a' <= s.at(1) && s.at(1) <= 'z'))ans = false;
	if (!('a' <= s.at(s.length() - 1) && s.at(s.length() - 1) <= 'z'))ans = false;
	int big = 0;
	for (int i = 2; i <= s.length()-2; i++) {
		if ('A' <= s.at(i) && s.at(i) <= 'Z')big++;
	}
	if (big == 0 || big >= 2)ans = false;
	if (ans)cout << "AC" << endl;
	else cout << "WA" << endl;
}