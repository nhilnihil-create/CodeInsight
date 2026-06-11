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

ll dp[100010];

int main() {
  fill_n(dp, 100005, INF);
  dp[0] = 0;

  ll N, K;
  scanf("%lld %lld", &N, &K);

  vector<ll> list;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list.emplace_back(v);
  }

  for (ll n = 0; n < N - 1; n++) {
    for (ll j = 1; j <= K; j++) {
      ll nn = n + j;
      if (nn >= N) {
        continue;
      }
      ll s = abs(list[n] - list[nn]);
      dp[nn] = min(dp[nn], dp[n] + s);
    }
  }

  cout << (dp[N - 1]) << endl;
}
