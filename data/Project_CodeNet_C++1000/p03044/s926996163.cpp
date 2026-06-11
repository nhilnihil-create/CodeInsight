#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

vector<l_l> r[100005];

ll color[100005];

void calc(ll node, ll dist) {
  if (color[node] >= 0) {
    return;
  }

  color[node] = (dist % 2 == 0) ? 0 : 1;

  auto l = r[node];

  for (ll i = 0; i < l.size(); i++) {
    ll next_node = l[i].first;
    ll next_dist = l[i].second;
    calc(next_node, dist + next_dist);
  }
}

int main() {
  fill_n(color, 100002, -1);

  ll N;
  scanf("%lld", &N);

  for (ll i = 0; i < N; i++) {
    ll u, v, w;
    scanf("%lld %lld %lld", &u, &v, &w);

    r[u].emplace_back(make_pair(v, w));
    r[v].emplace_back(make_pair(u, w));
  }

  calc(1, 0);

  for (ll i = 1; i <= N; i++) {
    cout << (color[i]) << endl;
  }
}
