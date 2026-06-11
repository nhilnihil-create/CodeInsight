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
  vector<ll> a(N);
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    ll cnt = 0;
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      cnt++;
    }
    ans += cnt;
  }
  cout << ans << endl;
  return 0;
}