#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int x[100010], l[100010]; 
int main() {
  int n, m;
  cin >> n >> m;
  rep(i,m) cin >> x[i];
  sort(x,x+m);
  
  rep(i,m-1) l[i] = x[i+1] - x[i];
  sort(l,l+(m-1), greater<int>());
  
  ll ans = x[m-1] - x[0];
  rep(i,n-1) ans -= l[i];
  
  if (n >= m) ans = 0;
  cout << ans << endl;


  return 0;
}