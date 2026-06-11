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
  // std::cout << std::fixed << std::setprecision(10);
  ll N, K;
  scanf("%lld %lld", &N, &K);

  vector<ll> list(N);
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list[i] = v;
  }
  sort(list.begin(), list.end());

  ll left = 0;
  ll right = K - 1;

  ll ans = INF;
  for (;;) {
    ll df = list[right] - list[left];
    ans = min(ans, df);

    left++;
    right++;

    if (right >= N) {
      break;
    }
  }
  cout << ans << endl;
}
