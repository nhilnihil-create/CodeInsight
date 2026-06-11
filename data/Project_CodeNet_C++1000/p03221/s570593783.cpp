#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979323846;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(M), Y(M);
  for (int i=0; i<M; i++) {
    cin >> P[i] >> Y[i];
    P[i]--;
  }
  // vals[v]:=(P[i]=vであるようなiについてのY[i]の値を集めたもの)
  vector<vector<int>> vals(N);
  for (int i=0; i<M; i++) vals[P[i]].push_back(Y[i]);
  // 各P[i]の値に対して
  for (int i=0; i<N; i++) {
    sort(vals[i].begin(), vals[i].end());
    // 数のダブりをなくす
    vals[i].erase(unique(vals[i].begin(), vals[i].end()), vals[i].end());
  }
  // 答え
  for (int i=0; i<M; i++) {
    int v = P[i];
    printf("%06d", v+1);
    // 座標圧縮して導いた答え
    int id = lower_bound(vals[v].begin(), vals[v].end(), Y[i])-vals[v].begin();
    printf("%06d\n", id+1);
  }
}