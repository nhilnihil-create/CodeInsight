#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
ll a[100010], num[45];
int main() {
	int n; ll k;
	cin >> n >> k;
	rep(i,n) {
		cin >> a[i];
		rep(j,40) {
			if ((a[i]>>j) & 1) num[j]++;
		}
	}

	ll x = 0;
	for (int i = 39; i >= 0; i--)	{
		if (num[i] * 2 <= n) x += (1LL << i);
		if (x > k) x -= (1LL << i);
	}
	ll ans = 0;
	rep(i,n) {
		ans += x ^ a[i];
	}
	cout << ans << endl;
	return 0;
}
