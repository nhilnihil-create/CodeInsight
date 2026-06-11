#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 100005;
//////////////////////////////

int n;
string p;
Int dp[3300][3300];
Int dp_sum[3300][3300];

int main()
{
	cin >> n;
	cin >> p;
	dp[0][0] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i - 1; j++) {
			dp_sum[i - 1][j] = dp[i - 1][j];
			if (j - 1 >= 0) dp_sum[i - 1][j] += dp_sum[i - 1][j - 1];
			dp_sum[i - 1][j] %= MOD;
		}
		for (int j = 0; j <= i; j++) {
			if (p[i - 1] == '<') {
				if (j - 1 >= 0) dp[i][j] = dp_sum[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp_sum[i - 1][i - 1];
				if (j - 1 >= 0) dp[i][j] -= dp_sum[i - 1][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}

	Int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += dp[n - 1][i];
		ans %= MOD;
	}
	if (ans < 0) ans += MOD;
	cout << ans << endl;

	return 0;
}
