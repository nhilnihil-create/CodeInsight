#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
#define MOD 1000000007
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define ff first
#define ss second
#define INF (1LL<<61)

using namespace std;

int n ;
double p[3010];
double dp[3010][3010];

double solve(int i , int x) {

	if (x == 0)return 1;

	if (i == 0)return 0;

	if (dp[i][x] > -0.9)return dp[i][x];

	return dp[i][x] =  p[i] * solve(i - 1 , x - 1) + (1 - p[i]) * solve(i - 1 , x);

}

int32_t main() {

	fastio
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w", stdout);
// #endif

	memset(dp , -1, sizeof(dp));
	cin >> n;
	for (int i = 1 ; i <= n  ; i++)cin >> p[i];

	cout << fixed << setprecision(10) << solve( n , (n + 1) / 2) << '\n';

	return 0;
}
