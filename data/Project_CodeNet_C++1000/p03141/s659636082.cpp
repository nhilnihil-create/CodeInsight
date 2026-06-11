#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n; cin >> n;
  vector<P> ab(n);
  
  for (int i = 0; i < n; ++i) cin >> ab[i].first >> ab[i].second;
  sort(ab.begin(), ab.end(), [](P &p1, P &p2){ return p1.first + p1.second > p2.first + p2.second; });
  
  ll t = 0, a = 0;
  for (int i = 0; i < n; ++i)
    if (i % 2 == 0) t += ab[i].first;
    else a += ab[i].second;
  
  cout << t - a << endl;
}