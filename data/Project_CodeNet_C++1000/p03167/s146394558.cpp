#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define forn(i,x,y) for(int i=x;i<y;++i)
#define fornr(i,x,y) for(long long i=x;i>=y;--i)
#define testcase int _t; cin >> _t; while(_t--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e3+10;
int dp[MAXN][MAXN]; //
int main()
{
	ios_base :: sync_with_stdio(false);
  	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int h,w;
	cin >> h >> w;
	char grid[h+1][w+1];
	ll mod = (int)1e9+7;
	forn(i,1,h+1)
		forn(j,1,w+1)
			cin >> grid[i][j];
	dp[1][1] = 1;
	forn(i,1,h+1)
		grid[i][0] = '!';	    
	forn(i,1,w+1)
		dp[0][i] = '!';	    
	forn(i,1,h+1){
		forn(j,1,w+1){
			if(grid[i][j] == '#') continue;
			if(grid[i][j-1] == '.')
				dp[i][j] += (dp[i][j-1]%mod);
			if(grid[i-1][j] == '.')
				dp[i][j] += (dp[i-1][j]%mod);
			dp[i][j] %= mod;
		}
	}
	cout << dp[h][w];  	
  	return 0;
}

 	/* 















 	*/
