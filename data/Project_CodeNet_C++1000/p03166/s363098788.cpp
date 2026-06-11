#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

vector<vector<int>> par(100100,vector<int>(0));
vector<bool> seen(100100,0);
vector<int> dp(100100,-1);

int f(int x){
  if(seen[x]) return dp[x];
  seen[x] = 1;
  int ans = 0;
  for(int p : par[x]){
    ans = max(ans, f(p)+1);
  }
  dp[x] = ans;
  return ans;
}

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int x,y;
    cin >> x >> y;
    par[y].push_back(x);
  }
  rep1(i,n) f(i);
  int ans = 0;
  rep1(i,n) ans = max(ans, dp[i]);
  cout << ans << endl;
}