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

ll dp[100010][3];

void show_table(ll I, ll J) {
  for (ll i = 0; i <= I; i++) {
    for (ll j = 0; j <= J; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "" << endl;
  }
  cout << "" << endl;
}

int main() {
  fill(dp[0], dp[100005], -INF);
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;

  ll N;
  scanf("%lld", &N);

  vector<tuple<ll, ll, ll>> list;
  for (ll i = 0; i < N; i++) {
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    list.emplace_back(make_tuple(a, b, c));
    // cout << get<0>(list[i]) << endl;
  }

  for (ll n = 0; n < N; n++) {
    for (ll type = 0; type <= 2; type++) {
      ll vals[3];
      vals[0] = get<0>(list[n]);
      vals[1] = get<1>(list[n]);
      vals[2] = get<2>(list[n]);
      for (ll next_type = 0; next_type <= 2; next_type++) {
        if (type == next_type && n > 0) {
          continue;
        }

        ll plus = vals[next_type];
        dp[n + 1][next_type] = max(dp[n + 1][next_type], dp[n][type] + plus);
      }
    }
  }

  ll a = max(max(dp[N][0], dp[N][1]), dp[N][2]);
  cout << (a) << endl;
}
