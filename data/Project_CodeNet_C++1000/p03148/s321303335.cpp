#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

int main()
{
  int64_t N, K, t, d;
  cin >> N >> K;
  vector<priority_queue<int64_t>> vpq(MAXN);
  for (int i = 0; i < N; i++)
  {
    cin >> t >> d;
    vpq[t].push(d);
  }
  priority_queue<pair<int64_t, int64_t>> pq;
  for (int i = 0; i < MAXN; i++)
  {
    if (vpq[i].empty())
      continue;
    pq.emplace(vpq[i].top(), 1);
    vpq[i].pop();
    while (vpq[i].size())
    {
      pq.emplace(vpq[i].top(), 0);
      vpq[i].pop();
    }
  }
  int64_t tmp = 0, ans = 0;
  priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq0, pq1;
  for (int i = 0; i < K; i++)
  {
    tmp += pq.top().first;
    if (pq.top().second)
      pq1.push(pq.top().first);
    else
      pq0.push(pq.top().first);
    pq.pop();
  }
  tmp += pq1.size() * pq1.size();
  ans = max(ans, tmp);
  while (pq.size())
  {
    if (pq.top().second)
    {
      tmp -= pq1.size() * pq1.size();
      if (pq0.empty())
      {
        cout << ans << endl;
        return 0;
      }
      tmp -= pq0.top();
      pq0.pop();
      tmp += pq.top().first;
      pq1.push(pq.top().first);
      tmp += pq1.size() * pq1.size();
    }
    ans = max(ans, tmp);
    pq.pop();
  }
  cout << ans << endl;
}
