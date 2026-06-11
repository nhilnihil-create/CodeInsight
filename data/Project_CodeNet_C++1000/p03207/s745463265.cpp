#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  ll N;
  scanf("%lld", &N);

  vector<ll> list(N);
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list[i] = v;
  }
  sort(list.rbegin(), list.rend());

  ll a = list[0] / 2;
  for (ll i = 1; i < list.size(); i++) {
    a += list[i];
  }
  cout << a << endl;
}
