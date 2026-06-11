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
  ll a, b;
  vector<pair<ll, ll>> p(N);
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    p.emplace_back(a, b);
  }
  sort(p.begin(), p.end());
  ll ans = 0;
  ll i = 0;
  ll cnt = 0;
  while (cnt < M) {
    if (cnt + p[i].second < M) {
      ans += p[i].first * p[i].second;
    } else {
      ans += p[i].first * (M - cnt);
    }
    cnt += p[i].second;
    i++;
  }
  cout << ans << endl;
  return 0;
}