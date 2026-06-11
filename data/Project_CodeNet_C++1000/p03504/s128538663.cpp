#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;



int main()
{
  ll N, C;
  cin >> N >> C;
  vector<vector<pll>> temp(C);//start end
  //connect time in same chanel
  for (ll i = 0; i < N; ++i)
  {
    ll s, t, c;
    cin >> s >> t >> c;
    temp.at(c - 1).push_back({s, t});
  }
  for (ll i = 0; i < C; ++i)
  {
    sort(temp.at(i).begin(), temp.at(i).end(), [] (pll a, pll b){
      return a.second < b.second;
    });
  }
  vector<pll> time_table;
  for (ll i = 0; i < C; ++i)
  {
    if (temp.at(i).size() == 0)
    {
      continue;
    }
    ll s = temp.at(i).at(0).first;
    ll e = temp.at(i).at(0).second;
    for (ll j = 1; j < temp.at(i).size(); ++j)
    {
      if (e == temp.at(i).at(j).first)
      {
        e = temp.at(i).at(j).second;
      }
      else
      {
        time_table.push_back({s, e});
        s = temp.at(i).at(j).first;
        e = temp.at(i).at(j).second;
      }
    }
    time_table.push_back({s, e});
  }
  sort(time_table.begin(), time_table.end(), [] (pll a, pll b){
    return a.second < b.second;
  });
  vector<ll> ans(100010, 0);
  for (ll i = 0; i < time_table.size(); ++i)
  {
    ans.at(time_table.at(i).first) += 1;
    ans.at(time_table.at(i).second + 1) -= 1;
  }
  for (ll i = 0; i < 100009; ++i)
  {
    ans.at(i + 1) += ans.at(i);
  }
  ll cnt = 0;
  for (ll i = 0; i < 100010; ++i)
  {
    cnt = max(cnt, ans.at(i));
  }
  cout << cnt << endl;

  // for (ll i = 0; i < time_table.size(); ++i)
  // {
  //   cout << time_table.at(i).first << " " << time_table.at(i).second << endl;
  // }
}
