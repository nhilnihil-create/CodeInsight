#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    int t = 0;
    for (int j = 0; j < 10; j++) {
      t *= 2;
      int k;
      cin >> k;
      if (k == 1) t++;
    }
    f[i] = t;
  }

  vector<vector<ll>> p(n, vector<ll>(11));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 11; j++) {
      cin >> p[i][j];
    }
  }

  ll max_get = -LLINF;
  for (int i = 1; i < (1<<10); i++) {
    ll get = 0;
    for (int j = 0; j < n; j++) {
      int store = f[j];
      int cnt = 0;
      for (int time = 0; time < 10; time++) {
        if ((store >> time) & (i >> time) & 1) cnt++;
      }
      get += p[j][cnt];
    }
    max_get = max(max_get, get);
  }

  cout << max_get << endl;
}
