#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  vector<vector<long long>> dp(n,vector<long long> (2, 1));
  for(int i=0;i<n-1;i++){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    tree[x].emplace_back(y);
    tree[y].emplace_back(x);
  }
  function<void(int, int)> dfs = [&, &dfs](int now, int root){
    for(int to:tree[now]){
      if(to != root) {
        dfs(to, now);
        dp[now][0] *= (dp[to][0]+dp[to][1]);
        dp[now][1] *= dp[to][0];
        dp[now][0] %= MOD;
        dp[now][1] %= MOD;
      }
    }
    return;
  };
  dfs(0, -1);
  cout << (dp[0][0]+dp[0][1]) % MOD <<endl;
}