#include <bits/stdc++.h>
 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define sortv(vv) sort(vv.begin(), vv.end())
 
using namespace std;
const ll maxn=1e3+100,inf=1e18,LOG=23,mod=1e9 + 7;
 
#define int ll

int n, dp[maxn][20010], w[maxn], s[maxn], v[maxn], ind[maxn];

bool comp(int i, int j)
{
	return s[i] - w[j] > s[j] - w[i];
}

main()
{
	cin >> n;
	forn(1, i, n)
	{
		cin >> w[i] >> s[i] >> v[i];
		ind[i] = i;
	}
	sort(ind + 1, ind + 1 + n, comp);
	forn(1, i, n)
	{
		forn(0, solid, 10000)
		{
			dp[i][solid] = dp[i - 1][solid];
			if(solid <= s[ind[i]])
			{
				dp[i][solid] = max(dp[i][solid], dp[i - 1][solid + w[ind[i]]] + v[ind[i]]);
			}
		}
	}
	int ans = 0;
	forn(0, solid, 10000)
	{
		ans = max(ans, dp[n][solid]);
	}
	cout << ans;
}