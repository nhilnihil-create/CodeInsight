#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  ll ans = 0;
  for (ll i = 0; i < N - 1; ++i) {
    for (ll j = 0; j < N; ++j) {
      ans = max(ans, abs(A.at(i) - A.at(j)));
    }
  }
  cout << ans << "\n";
}
