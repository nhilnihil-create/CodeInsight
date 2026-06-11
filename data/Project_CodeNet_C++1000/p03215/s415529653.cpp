#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N + 1, 0);
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    A.at(i + 1) = A.at(i) + a;
  }
  vector<ll> sum((N * (N + 1)) / 2);
  ll cnt = 0;
  for (ll i = 0; i < N; ++i) {
    for (ll j = i + 1; j < N + 1; ++j) {
      sum.at(cnt) = A.at(j) - A.at(i);
      cnt += 1;
    }
  }
  // cout << "sum" << endl;
  // for (ll i = 0; i < N * (N + 1) / 2; ++i) {
  //   cout << sum.at(i) << ' ';
  // }


  for (ll i = 40; i >= 0; --i) {
    vector<ll> temp;
    for (ll j = 0; j < sum.size(); ++j) {
      ll i_pow = pow(2, i);
      if (sum.at(j) & i_pow) {
        // cout << "sum" << sum.at(j) << "ipow" << i_pow << "i" << i << endl;
        temp.push_back(sum.at(j));
      }
    }
    if (temp.size() < K) {
      continue;
    }
    if (temp.size() == K) {
      ll ans = temp.at(0);
      for (ll j = 0; j < K; ++j) {
        ans = (ans & temp.at(j));
      }
      cout << ans << endl;
      return 0;
    }
    sum = temp;
  }
  ll ans = sum.at(0);
  for (ll j = 0; j < sum.size(); ++j) {
    ans = (ans & sum.at(j));
  }
  // cout << "sum" << endl;
  // for (ll i = 0; i < sum.size(); ++i) {
  //   cout << sum.at(i) << endl;
  // }
  cout << ans << endl;

}
