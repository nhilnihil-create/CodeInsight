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

int h, w, x;
char a[1001][1001];
int dp[1001][1001];

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> h >> w;
  rep(i, 1, h){
  	rep(j, 1, w){
  		cin >> a[i][j];
  	}
  }
  rep(i, 1, h){
  	rep(j, 1, w){
  		dp[i][j]=0;
  	}
  }
  dp[1][1]=1;
  rep(i, 1, h){
  	rep(j, 1, w){
  		if(i==1 && j==1) continue;
  		if(a[i][j]=='#') continue;
  		dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
  		// cout << "dp["<<i<<"]["<<j<<"] "<<dp[i][j]<<endl;
  	}
  }

  cout << dp[h][w];
}