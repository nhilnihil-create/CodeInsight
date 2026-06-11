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
	ll n,m;
	cin >> n >> m;

	//処理
	ll ans = 0;
	if (n == 1 && m == 1) {
		ans = 1;
	}
	else if (n == 1) {
			ans = m - 2;
	}
	else if (m == 1) {
		ans = n - 2;
	}
	else if (n > 1 && m > 1) {
		ans = (n - 2) * (m - 2);
	}

	//出力
	cout << ans << endl;

	return 0;
}
