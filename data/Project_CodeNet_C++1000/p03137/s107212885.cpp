#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  int mi = 1000000, ma = -10000000;
  int a[m];
  ll b[m - 1];
  b[0] = 0;
  rep(i, m) {
    cin >> a[i];
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
  }
  ll sum = abs(ma - mi);
  //cout << sum << endl;
  sort(a, a + m);
  rep(i, m - 1){
    b[i] = a[i + 1] - a[i];
    //cout << b[i] << endl;
  }
  sort(b, b + m - 1, greater<>());
  if(n >= m) cout << 0 << endl;
  else{
    rep(i, n - 1){
      sum -= b[i];
    }
    cout << sum << endl;
  }
  
  
        

  return 0;
}