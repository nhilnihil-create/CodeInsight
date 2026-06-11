#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) s[i] = 9 - (s[i] - '1') + '0';
	cout << s << endl;
	return 0;
}

