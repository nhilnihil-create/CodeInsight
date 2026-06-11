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
  ll N, M, C;
  cin >> N >> M >> C;
  vector<ll> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  ll a;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll sum = C;
    for (int j = 0; j < M; j++) {
      cin >> a;
      sum += a * B[j];
    }
    if (sum > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}