#include <bits/stdc++.h>
#define INF 1000000001
#define ll long long
using namespace std;
using pint = pair<int, int>;

int main()
{
  ll N;
  cin >> N;
  string S;
  cin >> S;
  vector<ll> e_sum(N, 0);
  vector<ll> w_sum(N, 0);
  for (ll i = 0; i < N; ++i)
  {
    if (S[i] == 'W')
    {
      w_sum.at(i) += 1;
    }
    else
    {
      e_sum.at(i) += 1;
    }
  }
  for (ll i = 0; i < N - 1; ++i)
  {
    w_sum.at(i + 1) += w_sum.at(i);
    e_sum.at(i + 1) += e_sum.at(i);
  }
  ll e_num = e_sum.at(N - 1);
  ll ans = INF;
  for (ll i = 0; i < N; ++i)
  {
    if (i == 0)
    {
      ans = e_num - e_sum.at(0);
      continue;
    }
    ans = min(ans, w_sum.at(i - 1) + (e_num - e_sum.at(i)));
    // cout << ans << endl;
  }
  cout << ans << endl;
  // cout << e_num << e_sum.at(0) << endl;
}
