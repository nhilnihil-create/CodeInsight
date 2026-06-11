#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;


int main() {
  int n, k; cin >> n >> k;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];
  sort(h.begin(),h.end());
  ll ans = INF;
  rep(i,n-k+1){
    ans = min(ans,h[i+k-1]-h[i]);
  }
  cout << ans << endl;
  return 0;
}