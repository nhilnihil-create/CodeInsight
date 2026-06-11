#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> t(N), d(N);
  for (int i = 0; i < N; i++) {
    cin >> t[i] >> d[i];
    t[i]--;
  }

  vector<pair<ll, int>> A(N);
  for (int i = 0; i < N; i++) {
    A[i] = make_pair(d[i], t[i]);
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  ll x = 0, y = 0;
  vector<bool> used(N);
  priority_queue<ll, vector<ll>, greater<ll>> que;
  for (int i = 0; i < K; i++) {
    y += A[i].first;
    if (!used[A[i].second]) {
      x++;
      used[A[i].second] = true;
    } else {
      que.push(A[i].first);
    }
  }
  ll ans = y + x * x;
  for (int i = K; i < N && !que.empty(); i++) {
    if (used[A[i].second]) continue;
    y -= que.top();
    que.pop();
    y += A[i].first;
    x++;
    used[A[i].second] = true;
    ans = max(ans, y + x * x);
  }
  cout << ans << endl;
}