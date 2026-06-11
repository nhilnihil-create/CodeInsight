#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N, M;
vector<ll> bipartite(vector<vector<ll>>& connection) {
  vector<ll> res = {1, 0};
  vector<ll> color(N, -1);
  color.at(0) = 0;
  queue<ll> q;
  q.push(0);
  while (!q.empty()) {
    ll now = q.front();
    q.pop();
    ll now_color = color.at(now);
    ll dif_color = (now_color + 1) % 2;
    for (ll i = 0; i < connection.at(now).size(); ++i) {
      ll check = connection.at(now).at(i);
      if (color.at(check) == now_color) {
        res.at(0) = -1;
        return res;
      }
      else if (color.at(check) == -1) {
        color.at(check) = dif_color;
        q.push(check);
        res.at(dif_color) += 1;
      }
    }
  }
  return res;
}

int main() {
  cin >> N >> M;
  vector<vector<ll>> connection(N);
  for (ll i = 0; i < M; ++i) {
    ll A, B;
    cin >> A >> B;
    A -= 1;
    B -= 1;
    connection.at(A).push_back(B);
    connection.at(B).push_back(A);
  }
  vector<ll> color_num = bipartite(connection);
  // cout << color_num.at(0) << color_num.at(1) << "\n";
  if (color_num.at(0) == -1) {
    ll ans = N * (N - 1) / 2 - M;
    cout << ans << "\n";
  }
  else {
    ll ans = color_num.at(0) * color_num.at(1);
    ans -= M;
    cout << ans << "\n";
  }
}
