#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

int main()
{
  int64_t n, k;
  cin >> n >> k;
  vector<priority_queue<int64_t>> vpq(MAXN);
  for (int i = 0; i < n; i++)
  {
    int64_t t, d;
    cin >> t >> d;
    vpq[t].push(d);
  }
  int64_t s1 = 0;
  vector<int64_t> v1, v2;
  for (int i = 0; i < MAXN; i++)
  {
    if (vpq[i].empty())
      continue;
    v1.emplace_back(vpq[i].top());
    vpq[i].pop();
    while (vpq[i].size())
    {
      v2.emplace_back(vpq[i].top());
      vpq[i].pop();
    }
  }
  sort(v1.begin(), v1.end(), greater<int64_t>());
  sort(v2.begin(), v2.end(), greater<int64_t>());
  int64_t ans = 0;
  for (int64_t i = 1; i <= min(k, (int64_t)v1.size()); i++)
  {
    int64_t tmp = accumulate(v1.begin(), v1.begin() + i, 0LL) + i * i;
    int j = k - i;
    if (j <= v2.size())
    {
      tmp += accumulate(v2.begin(), v2.begin() + j, 0LL);
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}