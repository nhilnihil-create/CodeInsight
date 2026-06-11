#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  priority_queue<int, vector<int>, greater<int>> pq;

  rep(i, 0, n) {
    int a;
    cin >> a;
    pq.push(a);
  }

  vector<P> v(m);
  rep(i, 0, m) cin >> v[i].second >> v[i].first;

  sort(v.rbegin(), v.rend());

  rep(i, 0, m) {
    rep(j, 0, v[i].second) {
      if (pq.top() < v[i].first) {
        pq.push(v[i].first);
        pq.pop();
      } else
        break;
    }
  }

  ll ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;
}
