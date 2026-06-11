#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n, ans = -1e10;
	cin >> n;
	int f[100][10] = {};
	rep(i,n) rep(j,10) cin >> f[i][j];
	ll p[100][11] = {};
	rep(i,n) rep(j,11) cin >> p[i][j];

	for(int i = 1; i < (1 << 10); i++) {
		ll sum = 0, count = 0;
		rep(k,n) {
			count = 0;
			rep(b,10) {
				if ((i >> b & 1)&&f[k][b]) count++;
			}
			sum += p[k][count];
		}
		if (ans < sum) ans = sum;
	}

	cout << ans << endl;
	return 0;
}
