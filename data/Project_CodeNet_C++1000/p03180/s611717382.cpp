#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INTF = 1e9 + 7;

int main() {  
  int n;
  cin >> n;

  vector<vector<ll>> v(n, vector<ll>(n));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> v[i][j];

  vector<ll> dp(1<<n), d(1<<n);

  for(int mask=0; mask < (1<<n); mask++)
  {
    ll ans =0;
    for(int i=0; i<n; i++)
    {
      if(mask & (1<<i))
      {
        for(int j=0 ;j<i;j++)
        {
          if(mask & (1<<j))
          {
            ans += v[i][j];
          }
        }
      }
    }
    dp[mask] = ans;
  }


  for (int i=1;i<(1<<n);i++){
    d[i] = -1e18;
    for (int j=i;j;j=(j-1)&i){
      if (d[i] < d[i-j] + dp[j])
        d[i] = d[i-j] + dp[j];
    }
  }
  
  cout<<d[(1<<n) - 1];
  return 0;
}