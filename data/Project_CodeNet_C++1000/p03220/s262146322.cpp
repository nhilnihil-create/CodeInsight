#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll N, T, A;
  cin >> N >> T >> A;
  float diff = INF;
  ll ans = INF;

  for (int i = 0; i < N; i++) {
    int h;
    cin >> h;
    float temp = T - h * 0.006;
    if (abs(A - temp) < diff) {
      diff = abs(A - temp);
      ans = i;
    }
  }
  cout << ans + 1 << endl;
}
