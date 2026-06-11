#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, t;
  cin >> n >> t;
  int a[n][2];
  rep(i, n){
    rep(j, 2){
      cin >> a[i][j];
    }
  }
  int ans = 10000, m = 10000;
  rep(i, n){
    if(a[i][1] <= t){
      m = min(m, a[i][0]);
    }
  }
  rep(i, n){
    if(a[i][0] == m){
      ans = m;
    }
  }
  if(ans != 10000) cout << ans << endl;
  else cout << "TLE" << endl;
  return 0;
}