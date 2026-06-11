#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
	int a, b;
	string s;
	cin >> a >> b >> s;
	bool ans = true;
	int tmp = 0;
	rep(i, a) {
		tmp = s[i] - '0';
		if (0 > tmp || tmp > 9)ans = false;
	}
	for (int i = a + 1; i < a + b + 1;i++) {
		tmp = s[i] - '0';
		if (0 > tmp || tmp > 9)ans = false;
	}
	if (s[a] != '-')ans = false;

	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
