#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;
Graph ans;
int step = 0;
void add(int i, int j) {
  vi t = {i, j, i, j + 1};
  ans.push_back(t);
  step++;
}
void next(int i, int j) {
  vi t = {i, j, i + 1, j};
  ans.push_back(t);
  step++;
}

int main() {
  //  cin.tie(0);
  // ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int H, W;
  Graph a;
  cin >> H >> W;

  REP(i, H) {
    vi tmp(W);
    REP(j, W) cin >> tmp.at(j);
    a.push_back(tmp);
  }
  REP(i, H) {
    REP(j, W) {
      if (a.at(i).at(j) % 2 == 0) continue;
      if (j == W - 1 && i < H - 1) {
        next(i, j);
        a.at(i + 1).at(j)++;
      } else if (j == W - 1 && i == H - 1)
        continue;
      else {
        add(i, j);
        a.at(i).at(j + 1)++;
      }
    }
  }

  cout << step << endl;
  for (auto x : ans) {
    printf("%d %d %d %d\n", x[0] + 1, x[1] + 1, x[2] + 1, x[3] + 1);
  }
  return 0;
}