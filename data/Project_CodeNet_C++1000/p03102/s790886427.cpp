#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i,m) cin >> b[i];
  int ans = 0;
  rep(i,n){
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    int sum = 0;
    rep(i,m){
      sum += a[i]*b[i];
    }
    sum += c;
    if(sum>0) ++ans;
  }
  cout << ans << endl;
  return 0;
}