#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 2e5 + 100;	
const int MOD = 1e9 + 7;
	
int n;
int c;
vector <int> f;
int sum[N];
int dp[N];

int main() {
	scanf ("%d", &n);
	int last = -1;
	f.pb(last);
	rep(i, 1, n) {
		scanf ("%d", &c);
		if (c != last) f.pb(c);
		last = c;
	}
	dp[0] = 1;
	rep(i, 1, ss(f) - 1) {
		sum[f[i]] = (sum[f[i]] + dp[i - 1]) % MOD;
		dp[i] = sum[f[i]] % MOD;
	}
	printf ("%d\n", dp[ss(f) - 1]);
	
    return 0;
}
