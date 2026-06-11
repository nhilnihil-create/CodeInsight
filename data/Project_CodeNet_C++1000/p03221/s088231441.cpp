#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  ll N, M;
  scanf("%lld %lld", &N, &M);

  vector<pair<ll, ll>> list;
  for (ll i = 0; i < M; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    list.emplace_back(make_pair(a, b));
  }
  auto sorted_list = list;

  sort(sorted_list.begin(), sorted_list.end());

  map<ll, map<ll, string>> m;

  for (ll i = 0; i < sorted_list.size(); i++) {
    auto v = sorted_list[i];

    ll seq = m[v.first].size() + 1;

    char buff[1024];
    sprintf(buff, "%06d%06d", (int)v.first, (int)seq);
    m[v.first][v.second] = buff;
    // cout << buff << endl;
  }

  for (ll i = 0; i < list.size(); i++) {
    auto v = list[i];

    string a = m[v.first][v.second];
    cout << a << endl;
  }
}
