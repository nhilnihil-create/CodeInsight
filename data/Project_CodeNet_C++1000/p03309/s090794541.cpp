#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    A.at(i) = a - i - 1;
  }
  sort(A.begin(), A.end());
  ll mid = A.at(N / 2);
  ll ans = 0;
  for (ll i = 0; i < N; ++i) {
    ans += abs(A.at(i) - mid);
  }
  cout << ans << endl;

}
