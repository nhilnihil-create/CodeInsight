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
	int x;
	cin >> x;

	//処理
	int ans = 0;
	for (int b = 1;b < 1000;++b) {
		for (int p = 2;p < 1000;++p) {
			ll y = pow(b, p);
			if (y <= x) {
				if (ans < y) ans = y;
			}
		}
	}

	//出力
	cout << ans << endl;

	return 0;
}