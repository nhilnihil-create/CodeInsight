#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, ans = 0;
  cin >> N >> K;
  map<int, int> mp;
  vector<pair<int64_t, int64_t>> vp(N);
  vector<int64_t> v1, v2, s1(N + 1, 0), s2(N + 1, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> vp[i].second >> vp[i].first;
  }
  sort(vp.begin(), vp.end());
  reverse(vp.begin(), vp.end());
  for (auto p : vp)
  {
    if (mp.count(p.second))
      v2.push_back(p.first);
    else
      v1.push_back(p.first);
    mp[p.second]++;
  }
  s1[0] = 0, s2[0] = 0;
  for (int i = 1; i <= v1.size(); i++)
  {
    s1[i] = s1[i - 1] + v1[i - 1];
  }
  for (int i = 1; i <= v2.size(); i++)
  {
    s2[i] = s2[i - 1] + v2[i - 1];
  }
  for (int64_t n = 1; n <= K; n++)
  {
    if (n > v1.size() || K - n > v2.size())
      continue;
    int64_t tmp = s1[n] + s2[K - n] + n * n;
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}