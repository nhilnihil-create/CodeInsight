#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  unsigned int N, K;
  cin >> N >> K;
  vector<int> mv, pv;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x >= 0)
      pv.push_back(x);
    else
      mv.push_back(-1 * x);
  }
  reverse(mv.begin(), mv.end());
  vector<int> pred;
  if (pv.size() > K - 1) pred.push_back(pv[K - 1]);
  if (mv.size() > K - 1) pred.push_back(mv[K - 1]);
  for (unsigned int i = 0; i < K - 1; i++) {
    if (pv.size() > i && mv.size() > K - i - 2) {
      pred.push_back(pv[i] * 2 + mv[K - i - 2]);
    }
    if (mv.size() > i && pv.size() > K - i - 2) {
      pred.push_back(mv[i] * 2 + pv[K - i - 2]);
    }
  }
  sort(pred.begin(), pred.end());
  cout << pred[0] << endl;
}
