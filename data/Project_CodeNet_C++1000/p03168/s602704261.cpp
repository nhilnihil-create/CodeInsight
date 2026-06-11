#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 			1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl 			'\n'
#define inf 			1e18
#define fi 				first
#define se 				second

int XX[8] = { +1, +1, +1, 0, 0, -1, -1, -1};
int YY[8] = { +1, 0, -1, +1, -1, +1, 0, -1};
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

double p[3000];
vector<vector<double>> dp(3000, vector<double>(3000, -1));
int n;

double solve(int ind, int h) {
	if (ind == n) {
		if (h > (n - h)) {
			return 1.0;
		}
		return 0.0;
	}

	if (dp[ind][h] != -1) return dp[ind][h];

	return dp[ind][h] = p[ind] * solve(ind + 1, h + 1) + (1.0 - p[ind]) * solve(ind + 1, h);
}

signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin >> n;

	for0(i, n) cin >> p[i];

	cout << fixed << setprecision(11) << solve(0, 0) << endl;

	return 0;
}