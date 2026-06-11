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
  string S;
  cin >> S;
  ll N = S.length();
  vector<ll> accum_w(N + 1, 0);
  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == 'W')
      accum_w[i] = accum_w[i + 1] + 1;
    else
      accum_w[i] = accum_w[i + 1];
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'B') {
      ans += accum_w[i];
    }
  }
  cout << ans << endl;
  return 0;
}