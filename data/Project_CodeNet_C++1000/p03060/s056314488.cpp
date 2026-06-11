#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  int n, x, y, ans=0;
  cin >> n;
  vi v(n), c(n);
  rep(i,n) cin >> v[i];
  rep(i,n) cin >> c[i];
  rep(i,n){
    if(v[i] - c[i] > 0) ans += v[i]-c[i];
  }
  cout << ans << endl;
}
