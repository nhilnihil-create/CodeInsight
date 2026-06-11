#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll A, B , Q;
  cin >> A >> B >> Q;
  vector<ll> s(A);
  vector<ll> t(B);
  for (ll i = 0; i < A; ++i)
  {
    cin >> s.at(i);
  }
  for (ll i = 0; i < B; ++i)
  {
    cin >> t.at(i);
  }
  for (ll i = 0; i < Q; ++i)
  {
    ll x;
    cin >> x;
    ll t_index = lower_bound(t.begin(), t.end(), x) - t.begin();
    ll s_index =  lower_bound(s.begin(), s.end(), x) - s.begin();
    // cout << t_index << ' ' << s_index << endl;
    ll ans = INF;
    ll front_t, back_t, front_s, back_s;
    // if (t_index != 0 && t_index != B && s_index != 0 && s_index != Q)
    // {
    //   front_t = x - t.at(t_index - 1);
    //   back_t = t.at(t_index) - x;
    //   front_s = x - s.at(s_index - 1);
    //   back_s = s.at(s_index) - x;
    //   ans = min(ans, front_t * 2 + back_s);
    //   ans = min(ans, front_s * 2 + back_t);
    //   ans = min(ans, max(front_t, front_s));
    //   ans = min(ans, max(back_t, back_s));
    //   cout << ans << endl;
    // }
    if (t_index != 0 && s_index != A)
    {
      front_t = x - t.at(t_index - 1);
      back_s = s.at(s_index) - x;
      ans = min(ans, front_t * 2 + back_s);
      ans = min(ans, front_t + back_s * 2);
    }
    // cout << ans << endl;
    if (s_index != 0 && t_index != B)
    {
      back_t = t.at(t_index) - x;
      front_s = x - s.at(s_index - 1);
      ans = min(ans, front_s * 2 + back_t);
      ans = min(ans, front_s  + back_t * 2);
    }
    // cout << ans << endl;
    if (s_index != 0 && t_index != 0)
    {
      front_t = x - t.at(t_index - 1);
      front_s = x - s.at(s_index - 1);
      ans = min(ans, max(front_t, front_s));
    }
    // cout << ans << endl;
    if (s_index != A && t_index != B)
    {
      back_t = t.at(t_index) - x;
      back_s = s.at(s_index) - x;
      ans = min(ans, max(back_t, back_s));
    }
    cout << ans << endl;
  }
}

// 2 3 1
// 100
// 600
// 400
// 900
// 1000
// 899
