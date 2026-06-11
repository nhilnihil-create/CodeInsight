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

int n, k, x;
vi a={0};

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n >> k;
  rep(i, 1, n){
  	cin >> x;
  	a.pb(x);
  }
  vector<vi> ps(n+1, vi(k+1));
  vector<vi> dp(n+1, vi(k+1));

  rep(i, 0, n){
  	dp[i][0]=1;
  }
  rep(i, 1, k){
  	dp[0][i]=0;
  }

  rep(i, 0, n){
  	rep(j, 0, k){
  		ps[i][j]=1;
  	}
  }
  rep(i, 1, n){
  	rep(j, 1, k){
  		dp[i][j]=(MOD+ps[i-1][j]-(a[i]<j? ps[i-1][j-a[i]-1]:0))%MOD;
  		ps[i][j]=(ps[i][j-1]+dp[i][j])%MOD;
  	}
  }
  cout << dp[n][k];
}