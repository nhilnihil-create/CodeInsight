#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll calc(vector<ll>& time)
{
  ll res = INF;
  for (ll i = 0; i < 24; ++i) {
    if (time.at(i) > 1) {
      return 0;
    }
    if (time.at(i) == 1) {
      for (ll j = 1; j <= 12; ++j) {
        if (time.at((i + j) % 24) == 1) {
          res = min(res, j);
          break;
        }
        ll temp = i - j;
        if (temp < 0) {
          temp += 24;
        }
        if (time.at(temp) == 1) {
          res = min(res, j);
          break;
        }
      }
    }
  }
  return res;
}

int main()
{
  ll N;
  cin >> N;
  vector<ll> D(N);
  vector<ll> time(24, 0);
  time.at(0) = 1;
  for (ll i = 0; i < N; ++i) {
    cin >> D.at(i);
    time.at(D.at(i)) += 1;
  }

  ll ans = 0;
  for (ll i = 0; i < (1 << 11); ++i) {
    vector<ll> temp = time;
    for (ll j = 0; j < 11; ++j) {
      if (i & (1 << j)) {
        if (temp.at(j + 1) >= 1) {
          temp.at(j + 1) -= 1;
          temp.at(23 - j) += 1;
        }
      }
    }
    ans = max(ans, calc(temp));
  }
  cout << ans << endl;
}
