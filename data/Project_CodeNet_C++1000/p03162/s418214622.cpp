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

int dp[100005][4];
int a[100005], b[100005], c[100005];
int n;

int vacation(int ind, int fl) {
	if (ind >= n) return 0;
	if (dp[ind][fl] != -1) return dp[ind][fl];
	int ans = 0;
	if (fl == 0) {
		int c1 = a[ind] + vacation(ind + 1, 1);
		int c2 = b[ind] + vacation(ind + 1, 2);
		int c3 = c[ind] + vacation(ind + 1, 3);
		ans = max({c1, c2, c3});
	} else if (fl == 1) {
		int c2 = b[ind] + vacation(ind + 1, 2);
		int c3 = c[ind] + vacation(ind + 1, 3);
		ans += max(c2, c3);
	} else if (fl == 2) {
		int c1 = a[ind] + vacation(ind + 1, 1);
		int c3 = c[ind] + vacation(ind + 1, 3);
		ans += max(c1, c3);
	} else {
		int c1 = a[ind] + vacation(ind + 1, 1);
		int c2 = b[ind] + vacation(ind + 1, 2);
		ans += max(c1, c2);
	}

	return dp[ind][fl] = ans;
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
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << vacation(0, 0);

	return 0;
}