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

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> x(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }
  ll ans = INF;
  for (int i = K - 1; i < N; i++) {
    ll cand1 = abs(x[i - K + 1]) + abs(x[i] - x[i - K + 1]);
    ll cand2 = abs(x[i]) + abs(x[i] - x[i - K + 1]);
    ans = min({ans, cand1, cand2});
  }
  cout << ans << endl;
  return 0;
}