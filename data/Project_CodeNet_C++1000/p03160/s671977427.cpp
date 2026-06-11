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
	int h[n];
	FOR(i,n) read(h[i]);
	int dp[n];
	dp[0] = 0,dp[1] = abs(h[1]-h[0]);
	for(int i=2;i<n;i++)
		dp[i] = min(abs(h[i]-h[i-1])+dp[i-1],abs(h[i]-h[i-2])+dp[i-2]);
	cout << dp[n-1] << '\n';
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

