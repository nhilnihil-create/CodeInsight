#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define fastcin() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define heap priority_queue
using namespace std;
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 5065, INF = 1e18; 
int n, a, b, p[maxn], cnt[maxn][maxn]; 

int dp[maxn][maxn]; // first i elements are sorted, and the last element that remains in the same position is j. 

signed main()
{
	cin >> n >> a >> b; 
	for(int i = 1; i <= n; i++) 
	 	cin >> p[i]; 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cnt[i][j] = cnt[i-1][j] + (p[i] <= j); 
		}
	}	
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) 
			dp[i][j] = INF; 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(p[i] >= j) {
				dp[i][j] = dp[i-1][j]; 
				continue; 
			} 
			dp[i][j] = min(dp[i-1][j] + b, dp[i-1][p[i]] + a * (cnt[i][j] - cnt[i][p[i]])); 
		}
	}
	cout << dp[n][n] << '\n'; 
}
