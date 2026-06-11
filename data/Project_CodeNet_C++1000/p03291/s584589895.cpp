#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

void add(ll &a, ll b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main(){
	string s;cin>>s;
	ll n = s.size();
	vector<vector<ll>> dp(3LL * n ,vector<ll>(5,0LL));
	dp[0][0] = 1LL;
	for(int i = 0; i < n; i++) {
		if (s[i] == '?'){
			for(int j = 0; j < 4; j++) {
				if (j != 0){
					dp[i + 1][j] = ((dp[i][j - 1] + (3LL * dp[i][j] % mod)) % mod);
				}
				else{
					dp[i + 1][j] = ((3LL * dp[i][j]) % mod);
				}
			}
		}
		else{
			int index = (s[i] - 'A') + 1;
			for(int j = 0; j < 4; j++) {
				if (j == index){
					dp[i + 1][j] = ((dp[i][j - 1] + dp[i][j]) % mod);
				}
				else{
					dp[i + 1][j] = dp[i][j];
				}
			}
			
			
		}
	}
	cout << dp[n][3] << endl;
	return 0;
}