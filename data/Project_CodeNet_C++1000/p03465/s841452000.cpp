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

const int maxn = 3000; 
int n, a[maxn], s; 
bool dp[maxn][150005]; 

signed main()
{
	cin >> n; 
	for(int i = 1; i <= n; i++) 
		cin >> a[i], s += a[i]; 	
	dp[0][0] = 1; 
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 100000; j++) {
			if(j < a[i]) dp[i][j] |= dp[i-1][a[i] - j]; 
			else dp[i][j] |= dp[i-1][j - a[i]]; 
			if(j + a[i] <= 100000) dp[i][j] |= dp[i-1][j + a[i]]; 
 		}
	}
	for(int i = 0; i <= 100000; i++) 
		if(dp[n][i]) 
			return cout << (s + i) / 2, 0; 
}
