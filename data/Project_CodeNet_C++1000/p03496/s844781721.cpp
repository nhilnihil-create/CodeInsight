// https://atcoder.jp/contests/abc081/tasks/arc086_b

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 50;
const int A_I_MAX = 1e6;

int N;
int a[N_MAX];

vector<pair<int, int>> ans;

void solve() {
  int ai = A_I_MAX + 1;
  int ax = -(A_I_MAX + 1);
  int ii = -1;
  int ix = -1;
  REP(i, N) {
    if (a[i] < ai) {
      ai = a[i];
      ii = i;
    }
    if (a[i] > ax) {
      ax = a[i];
      ix = i;
    }
  }
  bool positive = true;
  if (ai >= 0) {
    positive = true;
  } else if (ax <= 0) {
    positive = false;
  } else if (abs(ax) >= abs(ai)) {
    REP(i, N) if (a[i] < 0) {
      ans.push_back({ix, i});
      a[i] += ax;
    }
    positive = true;
  } else {
    REP(i, N) if (a[i] > 0) {
      ans.push_back({ii, i});
      a[i] += ai;
    }
    positive = false;
  }
  if (positive) {
    REP(i, N - 1) if (a[i + 1] < a[i]) {
      ans.push_back({i, i + 1});
      a[i + 1] += a[i];
    }
  } else {
    for (int i = N - 1; i > 0; i--) if (a[i - 1] > a[i]) {
      ans.push_back({i, i - 1});
      a[i - 1] += a[i];
    }
  }
  printf("%d\n", ans.size());
  for (auto p : ans) printf("%d %d\n", p.first + 1, p.second + 1);
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
}

int main() {
  input();
  solve();
  return 0;
}
