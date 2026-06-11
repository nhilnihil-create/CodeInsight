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

int dp[22][20000001];
bool comp[22][22];
int n;

int calc(int m, int w){
	if(dp[m][w]!=-1) return dp[m][w];
	if(m==n) return 1;
	int ans=0;
	rep(i, 0, n-1){
		if(!(w&(1<<i))) continue;
		if(comp[m][i]){
			ans=(ans+calc(m+1, w&(~(1<<i)))%MOD)%MOD;
		}
	}
	return dp[m][w]=ans;
}

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n;
  rep(i, 0, n-1){
  	rep(j, 0, n-1){
  		cin >> comp[i][j];
  	}
  }
  rep(i, 0, n){
  	rep(j, 0, (1<<(n+1))-1){
  		dp[i][j]=-1;
  	}
  }
  cout << calc(0, (1<<(n+1))-1);
}