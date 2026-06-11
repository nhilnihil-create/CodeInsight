#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll unsigned long long

const ll MOD = 1000000000000000000;

int main() {
	//入力
	int n;
	cin >> n;
	vector<string> s;
	rep(i, n) {
		string s1;
		cin >> s1;
		s.push_back(s1);
	}

	//処理
	vector<ll> a(5);
	rep(i, n) {
		string s1 = s[i].substr(0, 1);
		if (s1 == "M")
			++a[0];
		else if (s1 == "A")
			++a[1];
		else if (s1 == "R")
			++a[2];
		else if (s1 == "C")
			++a[3];
		else if (s1 == "H")
			++a[4];
	}

	//出力
	ll ans = 0;
	ans += a[0] * a[1] * a[2];
	ans += a[0] * a[1] * a[3];
	ans += a[0] * a[1] * a[4];
	ans += a[0] * a[2] * a[3];
	ans += a[0] * a[2] * a[4];
	ans += a[0] * a[3] * a[4];
	ans += a[1] * a[2] * a[3];
	ans += a[1] * a[2] * a[4];
	ans += a[1] * a[3] * a[4];
	ans += a[2] * a[3] * a[4];
	cout << ans << endl;

	return 0;
}