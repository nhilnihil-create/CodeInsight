#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,M,Q;
  cin >> N >> M >> Q;
  vector<P> train(M);
  int stop[N];
  int res[N][N];
  for (int i = 0; i < N; i++) stop[i] = 0;
  for (int i = 0; i < M; i++) {
    cin >> train[i].first >> train[i].second;
    train[i].first--;
    train[i].second--;
  }
  sort(train.begin(),train.end());
  for (int i = 0; i < M; i++) {
    stop[train[i].second]++;
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j == 0) {
        res[i][j] = stop[j];
      } else {
        res[i][j] = res[i][j-1] + stop[j];
      }
    }
    while (cnt != M && train[cnt].first == i) {
      stop[train[cnt].second]--;
      cnt++;
    }
  }

  for (int i = 0; i < Q; i++) {
    int p,q;
    cin >> p >> q;
    p--; q--;
    cout << res[p][q] << endl;
  }
  return 0;
}