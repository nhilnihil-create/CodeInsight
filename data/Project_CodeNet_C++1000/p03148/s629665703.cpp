#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;

  struct Sushi {
    ll t, d;
  };
  vector<Sushi> sushis(N);
  for (ll i = 0; i < N; i++) {
    cin >> sushis[i].t >> sushis[i].d;
    sushis[i].t--;
  }

  sort(sushis.begin(), sushis.end(),
       [&](Sushi& lhs, Sushi& rhs) { return lhs.d > rhs.d; });

  vector<bool> appear(N, false);
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll base = 0;
  ll type_num = 0;
  for (ll i = 0; i < K; i++) {
    base += sushis[i].d;
    if (appear[sushis[i].t]) {
      pq.push(sushis[i].d);
    } else {
      appear[sushis[i].t] = true;
      type_num++;
    }
  }
  ll ans = base + type_num * type_num;

  for (ll i = K; i < N && !pq.empty(); i++) {
    if (appear[sushis[i].t]) {
      continue;
    }

    ll t = pq.top();
    pq.pop();
    base += sushis[i].d - t;
    type_num++;
    ans = max(ans, base + type_num * type_num);
    appear[sushis[i].t] = true;
  }

  cout << ans << endl;
}
