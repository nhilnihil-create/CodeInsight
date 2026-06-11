#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
ll test[1234][1234];
signed main() {
	ll n = 0, a, cnt = 1, ans = 1; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> a; ans *= 3;
		if (a % 2 == 0) { cnt *= 2; }
	}
	cout << ans - cnt << endl;
	cin >> n; return 0;
}