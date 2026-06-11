#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, x;
vi s;
vector<ll> ps;
ll dp[401][401];

ll calc(int l, int r){
	if(dp[l][r]!=-1) return dp[l][r];
	if(l==r) return 0;

	ll ans=1e18;
	rep(i, l+1, r){
		ans=min(ans, ps[r]-(l==0?0:ps[l-1])+calc(l, i-1)+calc(i, r));
	}
	return dp[l][r]=ans;
}

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n;
  rep(i, 1, n){
  	cin >> x;
  	s.pb(x);
  	ps.pb(x+(i==1?0:ps[i-2]));
  }
  rep(i, 0, 400){
  	rep(j, 0, 400){
  		dp[i][j]=-1;
  	}
  }
  cout << calc(0, n-1);
}