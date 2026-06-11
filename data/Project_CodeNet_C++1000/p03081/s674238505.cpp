#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5;

int N, Q;
string s;
char t[MAX+10], d[MAX+10];

int simulate(int idx) {
  for (int i = 0; i < Q; i++) {
    if (t[i] != s[idx]) continue;

    (d[i] == 'L' ? idx-- : idx++);
    if (idx < 0 || idx >= N) break;
  }

  return idx;
}

bool isLeftFall(int idx) {
  return simulate(idx) < 0;
}

bool isRightFall(int idx) {
  return simulate(idx) >= N;
}

int main() {
  cin >> N >> Q >> s;
  for (int i = 0; i < Q; i++) cin >> t[i] >> d[i];

  // 二分探索で左の境界を探す
  int l = 0, r = N;
  while (r - l > 1) {
    int mid = (l + r) / 2;

    if (isLeftFall(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  // 二分探索で右の境界を探す
  int l2 = 0, r2 = N;
  while (r2 - l2 > 1) {
    int mid = (l2 + r2) / 2;

    if (isRightFall(mid)) {
      r2 = mid;
    } else {
      l2 = mid;
    }
  }

  cout << max(l2 - r + 1, 0) << endl;
  return 0;
}
