#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, Q;
ll A[2010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N >> K >> Q;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 1LL << 60;
  for (int i = 0; i < N; i++) {
    vector<ll> mins;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for (int j = 0; j < N; j++) {
      if (A[j] < A[i]) {
        while (que.size() >= K) {
          mins.emplace_back(que.top());
          que.pop();
        }
        que = priority_queue<ll, vector<ll>, greater<ll>>();
      } else {
        que.emplace(A[j]);
      }
    }
    while (que.size() >= K) {
      mins.emplace_back(que.top());
      que.pop();
    }
    sort(mins.begin(), mins.end());
    if (mins.size() >= Q) ans = min(ans, mins[Q-1] - A[i]);
  }
  cout << ans << endl;

  return 0;
}