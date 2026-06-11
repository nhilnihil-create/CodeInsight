#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define fastcin() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 100; 
int n, p[maxn], dp[maxn], pos[maxn], mx; 

signed main()
{
	cin >> n; 
	for(int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i; 
	for(int i = 1; i <= n; i++) {
		if(pos[i - 1] < pos[i]) dp[i] = dp[i-1] + 1; 
		else dp[i] = 1; 
		mx = max(mx, dp[i]); 
	}
	cout << n - mx; 
}
