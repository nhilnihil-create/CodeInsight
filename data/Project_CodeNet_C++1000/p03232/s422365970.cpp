#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 11451419198109130;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<int, PP> PPP;
struct edge { int to; int to2; int cost; };
int a[100006];

int modpow(int x, int n, int md) {
	if (!n)return 1;
	int res = modpow(x*x%md, n / 2, md);
	if (n & 1)res = res*x%md;
	return res;
}

int fsum[100005];

signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		fsum[i] = modpow(i, mod - 2, mod);
	}
	for (int i = 1; i < n; i++) {
		fsum[i + 1] += fsum[i];
		fsum[i + 1] %= mod;
	}
	int ans = 0;

	rep(i, n) {
		int l = i+1, r = n - i;
		ans += (fsum[r]+fsum[l]-1) * a[i];
		ans %= mod;
	}
	rep(i, n)ans = ans*(i + 1) % mod;
	cout << ans << endl;
}