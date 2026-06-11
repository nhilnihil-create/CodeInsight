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
const int MAXN = 2e5;


int main()
{
	ios_base :: sync_with_stdio(false);
  	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	string s,t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int dp[n+1][m+1];
	int ans = 0;
	forn(i,0,n+1)
		dp[i][0] = 0;
	forn(i,0,m+1)
		dp[0][i] = 0;
	int x,y;
	forn(i,1,n+1){
		forn(j,1,m+1){
			if(s[i-1] == t[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			if(dp[i][j] > ans){
				ans = dp[i][j];
				x = i, y = j;
			}
		}
	} 
	string tt = "";
//	cout << x << " " << y << '\n';
	if(!ans){
		cout << "";
	}else{
		while(x != 0 && y != 0){
//			cout << x << " " << y << '\n';
			if(s[x-1] == t[y-1]){
				tt += s[x-1];
				x--; y--;
//				cout << 1 << '\n';
			}else if(dp[x-1][y] > dp[x][y-1]){
				x--;
//				cout << 2 << '\n';
			}else if(dp[x][y-1] >= dp[x-1][y]){
				y--;
//				cout << 3 << '\n';
			}
		}
				
	}
	reverse(all(tt));
	cout << tt;  	      
	
  	return 0;
}

 	/* 















 	*/
