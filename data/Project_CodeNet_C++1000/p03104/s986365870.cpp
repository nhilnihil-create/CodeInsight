
// Problem : D - XOR World
// Contest : AtCoder - AtCoder Beginner Contest 121
// URL : https://atcoder.jp/contests/abc121/tasks/abc121_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 1;

ll a, b;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b;
	if (b - a <= 10) {
		ll ans = 0;
		for (ll i = a; i <= b; i++) {
			ans ^= i;
		}
		cout << ans;
		return 0;
	}
	ll ans = 0;
	while (a % 4 != 0) {
		ans ^= a;
		a++;
	}
	while (b % 4 != 3) {
		ans ^= b;
		b--;
	}
	cout << ans;
}