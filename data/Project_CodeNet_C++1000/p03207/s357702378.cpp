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
  ll N;
  cin >> N;
  vector<ll> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  sort(p.rbegin(), p.rend());
  p[0] = p[0] / 2;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += p[i];
  }
  cout << ans << endl;
  return 0;
}