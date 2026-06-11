#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> col(n);
  vector<vector<int>> v(200000);
  for(int i=0; i<n; ++i){
    cin >> col[i];
    --col[i];
    v[col[i]].push_back(i);
  }
  ll dp[n];
  dp[0] = 1;
  for(int i=1; i<n; ++i){
    dp[i] = dp[i-1];
    auto it = lower_bound(v[col[i]].begin(),v[col[i]].end(),i);
    if(it != v[col[i]].begin()){
      --it;
      if(*it +1 != i){
        dp[i] += dp[*it];
        dp[i] %= MOD;
      }
    }
  }
  cout << dp[n-1] << endl;
}