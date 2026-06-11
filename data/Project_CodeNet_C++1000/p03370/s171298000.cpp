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
  ll N, X;
  cin >> N >> X;
  vector<ll> m(N);
  ll res = X;
  for (int i = 0; i < N; i++) {
    cin >> m[i];
    res -= m[i];
  }
  sort(m.begin(), m.end());
  ll ans = N + res / m[0];
  cout << ans << endl;
  return 0;
}