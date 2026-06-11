#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, m, c;
  cin >> n >> m >> c;
  int b[m];
  int a[n][m];
  rep(i, m) cin >> b[i];
  rep(i,n){
    rep(j,m){
      cin >> a[i][j];
    }
  }
  int ans = 0, tmp = 0;
  rep(i,n){
    tmp = 0;
    rep(j,m){
      tmp += a[i][j] * b[j];
    }
    if(tmp + c > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}