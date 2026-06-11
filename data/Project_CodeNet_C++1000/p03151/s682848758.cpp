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
  vector<ll> A(N), B(N);
  priority_queue<ll> q;
  ll res = 0, sum_A = 0, sum_B = 0, x;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum_A += A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
    sum_B += B[i];
  }
  if (sum_A < sum_B) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    x = B[i] - A[i];
    res += max(0LL, x);
    if (x < 0) q.push(A[i] - B[i]);
    if (x > 0) ans++;
  }
  if (res == 0) {
    cout << 0 << endl;
    return 0;
  }
  while (!q.empty() && res > 0) {
    x = q.top();
    q.pop();
    res -= x;
    ans++;
  }
  if (res > 0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}