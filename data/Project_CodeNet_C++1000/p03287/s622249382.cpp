#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, M;
  cin >> N >> M;
  ll ans = 0;
  vector<ll> A(N + 1, 0);
  for (ll i = 0; i < N; ++i)
  {
    ll a;
    cin >> a;
    A.at(i + 1) = (A.at(i) + a) % M;
    // if (a % M == 0)
    // {
    //   ans += 1;
    // }
  }
  // for (int i = 0; i < N + 1; ++i)
  // {
  //   cout << A.at(i) << ' ';
  // }
  // cout << endl;
  sort(A.begin(), A.end());
  // for (int i = 0; i < N + 1; ++i)
  // {
  //   cout << A.at(i) << ' ';
  // }
  // cout << endl;
  ll cnt = 0;
  ll before = -1;
  for (ll i = 0; i < N + 1; ++i)
  {
    if (A.at(i) == before)
    {
      cnt += 1;
    }
    else
    {
      // cout << "cnt" << cnt << endl;
      ans += (cnt - 1) * cnt / 2;
      cnt = 1;
      before = A.at(i);
    }
  }
  ans += cnt * (cnt - 1) / 2;
  cout << ans << endl;
}
