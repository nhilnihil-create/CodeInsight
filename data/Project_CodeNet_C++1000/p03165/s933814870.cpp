#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	vector<char> a(n), b(m);
	rep(i, n) a[i] = (char)s[i];
	rep(i, m) b[i] = (char)t[i];
	vector<vector<int > > dp(n+1, vector<int > (m+1));
	
	int ma = 0;
	rep(i, n) {
		rep(j, m) {
			if(a[i] == b[j]) {
				dp[i+1][j+1] = dp[i][j] + 1;
			}
			else {
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
	}
	int len = dp[n][m];
	int i = n, j = m;
	vector<char> ans(len+1);
	while(len > 0){
		if(a[i-1] == b[j-1]){
			ans[len] = a[i-1];
			i--; j--; len--;
		}
		else if(dp[i][j] == dp[i-1][j]){
			i--;
		}
		else {
			j--;
		}
	}
	rep2(k, 1, dp[n][m]+1){
		cout << ans[k];
	}
	cout << endl;
}