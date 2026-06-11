#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
using pi = pair<int,int>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll LINF = (1LL<<60);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
int dp[10][10];
int table[500][500];

signed main(){
	//cout << fixed << setprecision(10);
    int n,m; cin >> n >> m;
	rep(i,0,10){
		rep(j,0,10){
			cin >> dp[i][j];
		}
	}
	rep(i,0,n){
		rep(j,0,m){
			cin >> table[i][j];
		}
	}
	rep(k,0,10){
		rep(i,0,10){
			rep(j,0,10){
				chmin(dp[i][j] , dp[i][k] + dp[k][j]);
			}
		}
	}
	int ans = 0;
	rep(i,0,n){
		rep(j,0,m){
			if(table[i][j] == -1)continue;
			ans += dp[table[i][j]][1];
		}
	}
	cout << ans << endl;

	return 0;
}