#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set

using namespace std;

const ll MOD = 1000000007;
const ll INF = (1LL << 62);

vector<ll> tmp_list;
vector<ll> ans_list;

int main() {
  // std::cout << std::fixed << std::setprecision(10);

  ll Na, Nb, Nc, K;
  scanf("%lld %lld %lld %lld", &Na, &Nb, &Nc, &K);

  vector<ll> alist(Na);
  vector<ll> blist(Na);
  vector<ll> clist(Na);

  for (ll i = 0; i < Na; i++) {
    ll v;
    scanf("%lld", &v);
    alist[i] = v;
  }
  for (ll i = 0; i < Nb; i++) {
    ll v;
    scanf("%lld", &v);
    blist[i] = v;
  }
  for (ll i = 0; i < Nc; i++) {
    ll v;
    scanf("%lld", &v);
    clist[i] = v;
  }

  sort(alist.begin(), alist.end(), greater<ll>());
  sort(blist.begin(), blist.end(), greater<ll>());
  sort(clist.begin(), clist.end(), greater<ll>());

  for (ll i = 0; i < alist.size(); i++) {
    for (ll j = 0; j < blist.size(); j++) {
      ll sum = alist[i] + blist[j];
      tmp_list.emplace_back(sum);
    }
  }
  sort(tmp_list.begin(), tmp_list.end(), greater<ll>());
  tmp_list.resize(K);

  for (ll i = 0; i < tmp_list.size(); i++) {
    for (ll j = 0; j < clist.size(); j++) {
      ll sum = tmp_list[i] + clist[j];
      ans_list.emplace_back(sum);
    }
  }
  sort(ans_list.begin(), ans_list.end(), greater<ll>());

  for (ll i = 0; i < K; i++) {
    cout << ans_list[i] << endl;
  }
}
