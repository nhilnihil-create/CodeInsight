#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
int F[105][10];
ll P[105][11];

int main() {
  ll N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> F[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 11; j++) {
      cin >> P[i][j];
    }
  }
  ll ans = -INF;
  for (int bit = 1; bit < (1 << 10); bit++) {
    vector<ll> cnt(N, 0);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 10; j++) {
        if (bit & (1 << j)) {
          if (F[i][j] == 1) cnt[i]++;
        }
      }
    }
    ll cost = 0;
    for (int i = 0; i < N; i++) {
      cost += P[i][cnt[i]];
    }
    ans = max(ans, cost);
  }
  cout << ans << endl;
  return 0;
}