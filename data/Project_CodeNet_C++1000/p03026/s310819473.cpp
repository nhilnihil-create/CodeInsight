#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<vector<ll>> connection(N);
  for (ll i = 0; i < N - 1; ++i) {
    ll a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    connection.at(a).push_back(b);
    connection.at(b).push_back(a);
  }
  ll ans = 0;
  vector<ll> c(N);
  for (ll i = 0; i < N; ++i) {
    cin >> c.at(i);
    ans += c.at(i);
  }
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  ans -= c.at(0);
  cout << ans << "\n";
  vector<ll> num(N, -1);
  queue<ll> q;
  q.push(0);
  num.at(0) = c.at(0);
  ll cnt = 1;
  while (!q.empty()) {
    ll now = q.front();
    q.pop();
    for (ll i = 0; i < connection.at(now).size(); ++i) {
      ll check = connection.at(now).at(i);
      if (num.at(check) != -1) {
        continue;
      }
      num.at(check) = c.at(cnt);
      cnt += 1;
      q.push(check);
    }
  }
  for (ll i = 0; i < N; ++i) {
    cout << num.at(i) << " ";
  }
  cout << "\n";
}
