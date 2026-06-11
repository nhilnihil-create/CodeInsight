
// Problem : O - Matching
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_o
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
//#define int long long
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int MOD = 1e9 + 7;
long long qread() {
	char c;
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 26;
int d[N][N];
int n;
int dp[lsh(N)];
int main() {
	n = qread();
	rep(i, n) rep(j, n) d[i][j] = qread();
	memset(dp, 0, sizeof(dp)); dp[0] = 1;
	rep(s, lsh(n) - 1) {
		int m = __builtin_popcount(s);
		rep(i, n) 
			if (d[m][i] && !(s & lsh(i))) 
				dp[s | lsh(i)] = (dp[s] + dp[s | lsh(i)]) % MOD;
	}
	cout << dp[lsh(n) - 1] << endl;
	return 0;
}
