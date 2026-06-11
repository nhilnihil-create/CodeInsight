#include <bits/stdc++.h>
using namespace std;
const int64_t MAXN = 10010;
vector<vector<int64_t>> Graph(MAXN);
vector<int64_t> Num(MAXN, 0);

int main()
{
  int64_t N, a, b, c, ans = 0;
  cin >> N;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> a >> b;
    a--, b--;
    Graph.at(a).push_back(b);
    Graph.at(b).push_back(a);
  }
  priority_queue<int64_t> pq;
  for (int i = 0; i < N; i++)
  {
    cin >> c;
    pq.push(c);
  }
  queue<int64_t> Q;
  Q.push(0);
  Num.at(0) = pq.top();
  pq.pop();
  while (Q.size())
  {
    auto cur = Q.front();
    Q.pop();
    for (auto next : Graph.at(cur))
    {
      if (Num.at(next))
        continue;
      Num.at(next) = pq.top();
      pq.pop();
      ans += Num.at(next);
      Q.push(next);
    }
  }
  cout << ans << endl;
  for (int i = 0; i < N; i++)
  {
    cout << Num.at(i);
    if (i == N - 1)
      cout << endl;
    else
      cout << ' ';
  }
}
