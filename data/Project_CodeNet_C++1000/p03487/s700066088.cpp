#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  map<int,int> m;
  ll ans = 0;
  rep(i,n) {
    cin >> a[i];
    m[a[i]]++;
  }
  for (auto p : m) {
    int d = p.first - p.second;
    if (d > 0) ans += p.second;
    else ans += abs(d);
  }
  cout << ans << endl;
  return 0;
}