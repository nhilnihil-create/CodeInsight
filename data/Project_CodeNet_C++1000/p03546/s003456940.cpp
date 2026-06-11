#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int h, w;
  cin >> h >> w;
  int c[10][10];
  REP(i, 10) {
    REP(j, 10) {
      int x;
      cin >> x;
      c[i][j] = x;
    }
  }
  int short_one[10];
  REP(i, 10) short_one[i] = INT_MAX;
  short_one[1] = 0;

  REP(i, 10) {
    if (i == 1) continue;
    vector<int> perm;
    REP(j, 10) {
      if (j != i) perm.push_back(j);
    }

    do {
      int tmp = 0;
      int from = i;
      REP(k, 9) {
        tmp += c[from][perm[k]];
        if (perm[k] == 1) break;
        from = perm[k];
      }
      short_one[i] = min(short_one[i], tmp);
    } while (next_permutation(ALL(perm)));
  }

  int ans = 0;
  REP(i, h) {
    REP(j, w) {
      int x;
      cin >> x;
      if (x == -1) continue;
      ans += short_one[x];
    }
  }
  cout << ans << endl;
}