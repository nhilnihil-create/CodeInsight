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

int a[100005];
int n;
vector<int> dp(100005, -1);

int frogA(int ind) {
	if (ind == (n - 1)) return 0;
	if (dp[ind] != -1) return dp[ind];
	int c1 = abs(a[ind] - a[ind + 1]) + frogA(ind + 1);
	int c2 = inf;
	if (ind + 2 < n)
		c2 = abs(a[ind] - a[ind + 2]) + frogA(ind + 2);
	return dp[ind] = min(c1, c2);
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

	for0(i, n) cin >> a[i];

	cout << frogA(0);

	return 0;
}