#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

bool compare(pair<int, int> a, pair<int, int> b)
{
  return a.second < b.second;
}

int main()
{
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> ab;
  ab.resize(M);
  for (int i = 0; i < M; ++i)
  {
    int a, b;
    cin >> a >> b;
    ab[i] = pair<int, int>(a, b);
  }
  sort(ab.begin(), ab.end(), compare);
  int last = 0;
  int ans = 0;
  for (int i = 0; i < M; ++i)
  {
    if (ab[i].first >= last)
    {
      last = ab[i].second;
      ++ans;
    }
  }
  cout << ans << endl;
}
