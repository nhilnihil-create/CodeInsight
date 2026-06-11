#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	string k = "keyence";

	string he = "";
	for (int i = 0; i < 7; i++) {
		if (s.at(i) == k.at(i))he += s.at(i);
		else break;
	}

	string ta = "";
	for (int i = 0; i < 7; i++) {
		if (s.at(s.length() - 1 - i) == k.at(6 - i))ta = k.at(6 - i) + ta;
		else break;
	}
	if (he.length() + ta.length() >= 7)cout << "YES" << endl;
	else cout << "NO" << endl;
}