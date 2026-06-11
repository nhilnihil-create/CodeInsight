#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define ll long long
#define double long double
#define INF LLONG_MAX/3
#define P pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
using namespace std;
int n, t[110], v[110], sum;
int speed[20010];
int kukan[20010];
int memo[20010];
double dp[20010][110];
signed main() {
	cin >> n;
	rep(i, n) {
		cin >> t[i];
		sum += t[i];
	}
	int cnt = 0;
	rep(i, n) {
		cin >> v[i];
		for (int j = cnt; j <= cnt + t[i]; j++) {
			if (!speed[j])speed[j] = INF;
			speed[j] = min(speed[j], v[i]);
			kukan[j] = i;
			if (j != cnt + t[i]) {
				memo[j] = v[i];
			}
		}
		cnt += t[i];
	}
	dp[0][0] = 1;
	REP(i, sum) {
		rep(j, speed[i] + 1) {
			if (j)if (dp[i - 1][j - 1])dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + j - 0.5);
			if (dp[i - 1][j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + j);
				if (j + 0.5 < memo[i-1])dp[i][j] = max(dp[i][j], dp[i - 1][j] + j + 0.25);
			}
			if (dp[i - 1][j + 1])dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + j + 0.5);
		}
	}
	printf("%.12Lf\n", dp[sum][0] - 1);
}