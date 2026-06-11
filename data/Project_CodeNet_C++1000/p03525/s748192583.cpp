#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n+1);
  d[0] = 0;
  rep(i, n) cin >> d[i+1];

  map<int, int> dict;
  for(auto v : d) {
    dict[v] += 1;
  }

  // d[i]==0, d[i]==12に2人いる場合は0
  if(dict[0] >= 2 || dict[12] >= 2) {
    cout << 0 << endl;
    return 0;
  }
  // d[i]に3人いる場合は0
  for(int i=1;i<=11;i++) {
    if(dict[i] >= 3) {
      cout << 0 << endl;
      return 0;
    }
  }

  // d[i]に2人いる場合は左右に振り分ける
  map<int, int> lr;
  for(int i=1;i<=11;i++) {
    int is = -1;
    if(dict[i] == 2) {
      rep(j, n+1) {
        if(d[j] == i) {
          lr[j] = is;
          is = 1;
        }
      }
    }
  }

  auto d_ij = [](int di, int dj) {
    int mx = max(di, dj);
    int mn = min(di, dj);
    return min(mx-mn, 24-(mx-mn));
  };

  auto get_d = [&](int mask, int i) {
    int di;
    if(d[i] == 0 || d[i] == 12) {
      di = d[i];
    } else if(lr[i] == 0) {
      di = mask & (1 << (d[i]-1)) ? d[i] : 24 - d[i];
    } else {
      di = lr[i] == 1 ? d[i] : 24 - d[i];
    }
    return di;
  };

  int ans = 0;
  for(int mask = 0; mask < (1 << 12); mask++) {
    int v = 100000000;
    rep(i, n+1) {
      rep(j, n+1) {
        if(i == j) continue;
        int di = get_d(mask, i);
        int dj = get_d(mask, j);
        v = min(v, d_ij(di, dj));
      }
    }
    ans = max(ans, v);
  }

  cout << ans << endl;
  return 0;
}
