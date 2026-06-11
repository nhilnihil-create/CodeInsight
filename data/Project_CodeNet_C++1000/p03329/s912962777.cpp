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
  ll res = N;
  for (int i = 0; i <= N; i++) {
    ll count = 0;
    ll t = i;
    while (t > 0) count += t % 6, t /= 6;
    t = N - i;
    while (t > 0) count += t % 9, t /= 9;
    res = min(res, count);
  }
  cout << res << endl;
  return 0;
}