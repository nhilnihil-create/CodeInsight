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
map<ll, ll> m;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  ll ans = 0, res;
  for (auto p : m) {
    res = abs(p.first - p.second);
    if (p.first > p.second || N <= res) {
      ans += p.second;
    } else {
      ans += res;
    }
  }
  cout << ans << endl;
  return 0;
}