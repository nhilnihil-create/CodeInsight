#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define sz(x) (int)(x.size())
#define all(x) (x).begin(),(x).end()
template<typename tp> void read(tp &x) {cin >> x;}
template<typename tp, typename... Args> void read(tp& x, Args&... args) {read(x);read(args...);}
const int mxN = (int)1e5,INF = (int)1e9,MOD = (int)1e9+7;

void solve()
{
	int n;
	read(n);
	int a[n][3];
	FOR(i,n) read(a[i][0],a[i][1],a[i][2]);
	int dp[n][3];//dp[i][j] max happy sum if he select the jth activity in the ith day
	FOR(i,3) dp[0][i] = a[0][i];
	for(int i=1;i<n;i++)
	{
		dp[i][0] = a[i][0] + max(dp[i-1][1],dp[i-1][2]);
		dp[i][1] = a[i][1] + max(dp[i-1][0],dp[i-1][2]);
		dp[i][2] = a[i][2] + max(dp[i-1][1],dp[i-1][0]);
	}
	cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test = 1;
	//read(test);
	while(test--)
		solve();
	return 0;
}

