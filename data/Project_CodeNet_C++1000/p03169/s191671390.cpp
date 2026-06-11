// " --- IN THE NAME OF ALLAH --- " // ;)
// ------------sphr_agz------------ // ;)
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair <lli, lli> pii;
#define pb push_back
#define recout(x) return cout << (x), 0
#define f first
#define s second
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define stp(x) cout << setprecision(x) << fixed
#define mk make_pair
#define all(x) x.begin(), x.end()
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
const lli N = 3e2 + 3, N2 = 2e5, delta = 46639, mod = 1e9 + 7, oo = 2e5, LOG = 20, SQ = 300;
const ld PI = 3.141592653589793;

ld dp[N][N][N], p[N];
lli cnt[5];

int32_t main() {
	fast;
	stp(9);
	lli n, x;
	cin >> n;
	for (lli i = 0; i < n; i++) {
		cin >> x;
		cnt[x - 1]++;
	}
	for (lli i = 0; i <= n; i++) {
		p[i] = 1;
		for (lli j = 0; j < oo; j++)
			p[i] = 1 + p[i] * (ld) i / (ld) n;
	}
	for (lli i = 0; i <= n; i++)
		for (lli j = 0; j <= n; j++)
			for (lli k = 0; k <= n; k++) {
				if (!(i + j + k) || i + j + k > n)
					continue;
				dp[k][j][i] = p[n - (i + j + k)] + (k? dp[k - 1][j][i] * (ld) k / (ld) (i + j + k): 0) + (j? dp[k + 1][j - 1][i] * (ld) j / (ld) (i + j + k): 0) + (i? dp[k][j + 1][i - 1] * (ld) i / (ld) (i + j + k): 0);
			}
	cout << dp[cnt[0]][cnt[1]][cnt[2]] << '\n';
	return 0;
}
