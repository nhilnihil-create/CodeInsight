#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define w(x)            int x; cin>>x; while(x--)
#define fr(i,a,b)       for(int i = a; i < b; i++)
#define mod				1000000007
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

vi tree[100002];
int dp[100002][2];

int independent(int src, bool is_black, int pr)
{
	if (dp[src][is_black] != -1)
		return dp[src][is_black];

	int ans = 0, w1 = 1, w2 = 1;
	for (auto child : tree[src])
	{
		if (child != pr)
		{
			// subtree with its parent is black
			w1 = (w1 * independent(child, 0, src)) % mod;
		}
	}

	ans += w1;
	if (!is_black)
	{
		for (auto child : tree[src])
		{
			if (child != pr)
			{
				//subtree with its parent is not black
				w2 = (w2 * independent(child, 1, src)) % mod;
			}
		}
		ans = (ans + w2) % mod;
	}

	return dp[src][is_black] = ans;

}
void solve()
{
	int n, x, y;
	cin >> n;
	fr(i, 1, n)
	{
		cin >> x >> y;
		tree[x].pb(y);
		tree[y].pb(x);
	}
	memset(dp, -1, sizeof(dp));
	cout << independent(1, 0, -1) << endl;
}

int32_t main()
{
	c_p_c();
	solve();
	return 0;
}