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
  ll N, M;
  cin >> N >> M;
  vector<ll> all_like(M, 0);
  for (int i = 0; i < N; i++) {
    ll k, a;
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> a;
      a--;
      all_like[a]++;
    }
  }
  ll ans = 0;
  for (auto cnt : all_like) {
    if (cnt == N) ans++;
  }
  cout << ans << endl;
  return 0;
}