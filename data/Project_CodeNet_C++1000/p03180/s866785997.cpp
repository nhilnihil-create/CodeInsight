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
#define all(v) v.begin(), v.end()
#define ld long double
#define ull unsigned long long
 
using namespace std;
const ll maxn=1e6+100,inf=1e18,LOG=23,mod=998244353;
int block = 300, timer = 0;
const ld EPS = 1e-7;
 
#define bt(i) (1 << (i))
#define int ll

int n, dp[maxn], cost[maxn], a[20][20];

main()
{
	IOS
	cin >> n;
	forn(1, i, n)
	{
		forn(1, j, n)
		{
			cin >> a[i][j];
		}
	}
	forn(0, mask, (1 << n))
	{
		forn(0, i, n)
		{
			if((mask & (1 << i)) > 0)
			{
				cost[mask] = cost[(mask ^ (1 << i))];
				//cout << mask << " " << i << " " << (mask ^ (1 << i)) << endl;
				forn(i + 1, j, n)
				{
					if((mask & (1 << j)) > 0)
					{
						cost[mask] += a[i + 1][j + 1];
					}
				}
				break;
			}
		}
	}
	//cout << cost[(1 << n) - 1] << endl;
	forn(0, mask, (1 << n))
	{
		for(int s = mask; s; s = (s-1) & mask)
		{
			dp[mask] = max(dp[mask], dp[(mask ^ s)] + cost[s]);
		}
	}
	cout << dp[(1 << n) - 1];
}