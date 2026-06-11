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
  ll N;
  scanf("%lld", &N);
  ll T, A;
  scanf("%lld %lld", &T, &A);

  ll min_temp_offset = INF;

  ll ans = -1;
  vector<ll> h_list;
  for (ll i = 1; i <= N; i++) {
    ll h;
    scanf("%lld", &h);

    ll temp = T * 1000 - h * 6;
    ll temp_offset = abs(temp - A * 1000);
    if (temp_offset < min_temp_offset) {
      ans = i;
      min_temp_offset = temp_offset;
    }
  }
  cout << ans << endl;
}
