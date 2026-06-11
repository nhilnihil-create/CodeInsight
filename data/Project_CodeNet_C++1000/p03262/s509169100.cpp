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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll N, X;
  cin >> N >> X;
  vector<ll> x(N);
  set<ll> res;
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    res.insert(abs(X - x[i]));
  }
  int cnt = 0;
  ll ans;
  for (auto e : res) {
    if (cnt == 0) {
      cnt++;
      ans = e;
      continue;
    }
    ans = gcd(ans, e);
  }
  cout << ans << endl;
  return 0;
}