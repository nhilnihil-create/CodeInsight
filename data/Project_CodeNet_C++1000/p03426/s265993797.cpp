#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T>using vv = vector<vector<T>>;

#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0;i<(n);++i)

int main() {
  int in(H); int in(W); int in(D);

  vv<int> A(H, vi(W, 0));
  map<int, pii> m;
  rep(i, H) rep(j, W) {
    int in(A);
    m[A] = pii(i, j);
  }
  vector<ll> cost(H*W+1, 0);
  rep(i, H*W-D+1)
    cost[i+D] = cost[i] + abs(m[i].first - m[i+D].first) + abs(m[i].second - m[i+D].second);
  int in(Q);
  rep(i, Q) {
    int in(l); int in(r);
    cout << cost[r] - cost[l] << endl;
  }

  return 0;
}
