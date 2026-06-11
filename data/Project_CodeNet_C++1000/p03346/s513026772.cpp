#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, p, ans = 0;
  cin >> N;
  map<int, int> mp;
  for (int i = 0; i < N; i++)
  {
    cin >> p;
    if (mp.count(p - 1))
    {
      mp[p] = mp[p - 1];
    }
    mp[p]++;
  }
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    ans = max(ans, (int64_t)(it->second));
  }
  cout << N - ans << endl;
}