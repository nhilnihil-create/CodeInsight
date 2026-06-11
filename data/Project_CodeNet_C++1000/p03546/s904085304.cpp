#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
#define mp make_pair
#define pb push_back
# define PI acos(-1)
# define double long double
const int MxN = 200005 ; 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i) 
# define RFOR(i,a,b) for(int i = b ; i > )
 
bool fun(const PII &a, const PII &b) {
	if(a.first == b.first) {
		return a.second > b.second ; 
	}

	return a.first < b.first ; 
}

ll dp[10][10] ; 


void solve() {
	int h ,w ; 
	ll c[10][10] ; 
	cin >> h >> w ; 
	FOR(i,0,10) {
		FOR(j,0,10) {
			cin >> c[i][j] ; 
			dp[i][j] = c[i][j] ; 
		}
	}

	FOR(k,0,10) {
		FOR(i,0,10) {
			FOR(j,0,10) {
				dp[i][j] = min(dp[i][j] ,(ll) dp[i][k] +(ll) dp[k][j]) ; 
			}
		}
	}



	int x ; 
	ll ans = 0 ; 
	FOR(i,0,h) {
		FOR(j,0,w) {
			cin >>x ; 
			if(x != -1)
			ans += (ll)dp[x][1] ; 
		}
	}
	cout << ans ;


	
 

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	
	int  t =1; 
	//cin >> t ; 
	while(t--)
		solve() ; 
	return 0 ; 
}

