#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
using LL = long long;

mt19937 rng( (int)chrono::steady_clock::now().time_since_epoch().count() );

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifdef FourLeafClover
  freopen("input", "r", stdin);
  #endif // FourLeafClover

  int l; cin >> l;
  int n = 20;
  vector<tuple<int, int, int> > edge;

  if ( (l >> 19) & 1) {
    vector<int> id(n);
    for (int i = 0, cur; i < 18; ++i, ++cur) {
      if (cur ^ i) {
        edge.emplace_back(i, i + 1, 0);
        edge.emplace_back(i, i + 1, 1 << cur);
        id[cur + 1] = i + 1;
      }
      else {
        if (i && !( (l >> i) & 1) ) {
          edge.emplace_back(i - 1, i, 1 << cur);
          edge.emplace_back(i - 1, i, (1 << cur) + (1 << (cur - 1) ) );
          id[cur + 1] = i;
          ++cur;
        }
        edge.emplace_back(i, i + 1, 0);
        edge.emplace_back(i, i + 1, 1 << cur);
        id[cur + 1] = i + 1;
      }
    }

    for (int i = 19; ~i; --i) if ( (l >> i) & 1) {
      l ^= 1 << i;
      edge.emplace_back(id[i], n - 1, l);
    }
  }
  else {
    for (int i = 0; i < 18; ++i) {
      edge.emplace_back(i, i + 1, 0);
      edge.emplace_back(i, i + 1, 1 << i);
    }

    for (int i = 18; ~i; --i) if ( (l >> i) & 1) {
      l ^= 1 << i;
      edge.emplace_back(i, n - 1, l);
    }
  }

  cout << n << ' ' << sz(edge) << '\n';
  for (const auto &i : edge) cout << get<0>(i) + 1 << ' ' << get<1>(i) + 1 << ' ' << get<2>(i) << '\n';

  return 0;
}
