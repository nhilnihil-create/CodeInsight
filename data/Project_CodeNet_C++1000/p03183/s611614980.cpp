#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e3 + 5;
const int W = 2e4 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;

struct node{
	int w, s, v;
}a[N];

bool cmp(node x, node y){
	return x.w + x.s < y.w + y.s;
}

int dp[N][W];
 
signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].w >> a[i].s >> a[i].v;
	}	
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		for(int x = 0; x < W; x++){
			dp[i][x] = max(dp[i-1][x], dp[i][x]);
			if(a[i].s >= x && x+a[i].w < W)
				dp[i][x+a[i].w] = max(dp[i][x+a[i].w], dp[i-1][x] + a[i].v);
		}
	}
	int ans = 0;
	for(int i = 0; i < W; i++)
		ans = max(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}