#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  map<int64_t, int64_t> mp;
  for (int i = 0; i < N; i++)
  {
    int64_t a;
    cin >> a;
    mp[a]++;
  }
  for (int i = 0; i < M; i++)
  {
    int64_t b, c;
    cin >> b >> c;
    mp[c] += b;
  }
  priority_queue<pair<int64_t, int64_t>> pq;
  for (auto p : mp)
  {
    pq.push(p);
  }
  int64_t ans = 0, n = 0;
  while (n < N)
  {
    auto t = pq.top();
    pq.pop();
    if (n + t.second <= N)
    {
      n += t.second;
      ans += t.first * t.second;
    }
    else
    {
      ans += t.first * (N - n);
      n = N;
    }
  }
  cout << ans << endl;
}