#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
const long long mod = 998244353;
const int maxN = 300001;
int kj[300005], kji[300005];

void setkj() {
	kj[0] = 1;
	kji[0] = kji[1] = 1;
	for (int i = 1; i <= maxN; i++)kj[i] = kj[i - 1] * i%mod;
	for (int i = 2; i <= maxN; i++)kji[i] = mod - (kji[mod%i] * (mod / i)) % mod;
	for (int i = 2; i <= maxN; i++)kji[i] = kji[i] * kji[i - 1] % mod;
}
int comb(int r, int c) {
	if (r < c)return 0;
	return kj[r] * kji[c] % mod*kji[r - c] % mod;
}

signed main() {
	setkj();
	int n, a, b, k; cin >> n >> a >> b >> k;
	int ans = 0;

	for (int i = 0; i <= n; i++) {
		int j = k - a*i;
		if (j >= 0 && j%b == 0) {
			ans += comb(n, i)*comb(n, j/b) % mod;
			ans %= mod;
		}
	}
	cout << ans << endl;
}