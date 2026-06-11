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
const ll maxn=3e3+100,inf=1e18,LOG=23,mod=1e9 + 7;
int block = 300, timer = 0;
const ld EPS = 1e-7;
 
#define bt(i) (1 << (i))
#define int ll

int n, pref[maxn][maxn], suff[maxn][maxn], dp[maxn][maxn];
string s;

main()
{
	cin >> n >> s;
	dp[1][1] = 1;
	pref[1][1] = 1;
	suff[1][1] = 1;
	forn(2, i, n)
	{
		forn(1, j, i)
		{
		//	dp[i][j] = dp[i - 1][j];
			if(s[i - 2] == '<')
				dp[i][j] += pref[i - 1][j - 1];
			else
				dp[i][j] += suff[i - 1][j];
			//cout << i << " " << j << " " << dp[i][j] << endl;
			dp[i][j] %= mod;
		}
		forn(1, j, i)
		{
			pref[i][j] = pref[i][j - 1] + dp[i][j];
			pref[i][j] %= mod;
		}
		nfor(1, j, i)
		{
			suff[i][j] = suff[i][j + 1] + dp[i][j];
			suff[i][j] %= mod;
		}
	}
	cout << pref[n][n];
}