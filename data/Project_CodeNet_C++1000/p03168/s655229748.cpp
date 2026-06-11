#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double n, p;
vector<double> prob={0};

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cout << setprecision(9)<<fixed;
  cin >> n;
  rep(i, 1, n){
  	cin >> p;
  	prob.pb(p);
  }
  vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
  dp[0][0]=1;
  rep(i, 1, n){
  	rep(j, 0, n){
  		if(j==0) dp[i][j]=dp[i-1][j]*(1-prob[i]);
  		else dp[i][j]=(1-prob[i])*dp[i-1][j]+prob[i]*dp[i-1][j-1];
  		// cout << "dp["<<i<<"]["<<j<<"] "<<dp[i][j]<<endl;
  	}
  }

  double ans=0;
  rep(i, n/2+1, n){
  	ans+=dp[n][i];
  }
  cout << ans;
}