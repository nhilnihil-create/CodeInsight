#include <bits/stdc++.h>
using namespace std;

bool f(string a, string b) {
	auto it = a.begin();
	for (char c : b) {
		if (it != a.end() && *it == c) {
			it++;
		}
	}
	return it == a.end();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	if (f("KIHBR", s) && f(s, "AKIHABARA")) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}
