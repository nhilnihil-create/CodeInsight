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
  vector<ll> A(N), accum(N, 0);
  map<ll, ll> m;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i == 0)
      accum[0] = A[0];
    else
      accum[i] = accum[i - 1] + A[i];
    m[accum[i]]++;
  }
  ll ans = m[0];
  for (auto p : m) {
    ans += p.second * (p.second - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}