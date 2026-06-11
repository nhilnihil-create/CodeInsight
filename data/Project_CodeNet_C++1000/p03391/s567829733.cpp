#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll INF = 1e15;

int main(){
  int n;
  cin >> n;
  ll a[n], b[n];
  ll ans = 0, r = INF;
  rep(i,n) {
    cin >> a[i] >> b[i];
    ans += a[i];
    if(a[i] > b[i]) r = min(b[i],r);
  }
  if(r == INF) cout << 0 << endl;
  else cout << ans - r << endl;
  return 0;
}