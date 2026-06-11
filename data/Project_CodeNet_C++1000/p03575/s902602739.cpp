#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#define INF 1000000000
#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
using namespace std;
using ll = long long;

vector<pair<int, int>> P;
int N, M;
ll G[50][50];
ll TMP[50][50];

bool check(int i) {
  rep(i, N) rep(j, N) TMP[i][j] = G[i][j];

  auto a = P[i].first;
  auto b = P[i].second;
  TMP[a][b] = INF;
  TMP[b][a] = INF;

  rep(k, N) {
    rep(i, N) {
      rep(j, N) { TMP[i][j] = min(TMP[i][j], TMP[i][k] + TMP[k][j]); }
    }
  }

  bool ret  = false;
  rep(i, N) {
    rep(j, N) {
      if (TMP[i][j] == INF)
        ret = true;
    }
  }
  return ret;
}

int main(void) {
  cin >> N >> M;
  rep(i, N) rep(j, N) G[i][j] = INF;

  rep(i, M) {
    int a, b;
    cin >> a >> b;
    G[a - 1][b - 1] = 1;
    G[b - 1][a - 1] = 1;
    P.push_back({a-1, b-1});
  }
  int ret = 0;
  rep(i, M) {
    if(check(i)) {
      ret++;
    }
  }
  cout << ret << endl;   
  return 0;
}
