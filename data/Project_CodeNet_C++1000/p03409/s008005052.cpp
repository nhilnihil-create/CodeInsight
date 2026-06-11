#include <bits/stdc++.h>
#define INF 1000000001
#define ll long long
using namespace std;
using pll = pair<ll, ll>;

int main()
{
  ll N;
  cin >> N;
  vector<pll> red(N);
  vector<pll> blue(N);
  for (ll i = 0; i < N; ++i)
  {
    cin >> red.at(i).first >> red.at(i).second;
  }
  for (ll i = 0; i < N; ++i)
  {
    cin >> blue.at(i).first >> blue.at(i).second;
  }
  sort(red.begin(), red.end(), [] (pll a, pll b){
    return a.second < b.second;
  });
  sort(blue.begin(), blue.end(), [] (pll a, pll b){
    return a.second < b.second;
  });
  vector<pll> pos_red;
  ll cnt = 0;
  ll ans = 0;
  for (ll i = 0; i < N; ++i)
  {
    pll b = blue.at(i);
    ll temp = cnt;
    // cout << "bsecond" << b.second << endl;
    for (ll j = temp; j < N; ++j)
    {
      // cout << "rsecond" << red.at(j).second << endl;
      cnt = j;
      if (b.second > red.at(j).second)
      {
        pos_red.push_back(red.at(j));
      }
      else
      {
        break;
      }
    }
    ll largest_first = -1;
    ll index;
    // cout << "pos_red" << endl;
    // for (ll j = 0; j < pos_red.size(); ++j)
    // {
    //   cout << pos_red.at(j).first << ' ' << pos_red.at(j).second << endl;
    // }
    for (ll j = 0; j < pos_red.size(); ++j)
    {
      if (pos_red.at(j).first < b.first && pos_red.at(j).first > largest_first)
      {
        largest_first = pos_red.at(j).first;
        index = j;
      }
    }
    if (largest_first != -1)
    {
      ans += 1;
      // cout << "pair" << endl;
      // cout << b.first << ' ' << b.second << endl;
      // cout << pos_red.at(index).first << ' ' << pos_red.at(index).second << endl;
      pos_red.erase(pos_red.begin() + index);
    }
    // cout << red.at(i).first << ' ' << red.at(i).second << endl;
  }
  cout << ans << endl;
}
