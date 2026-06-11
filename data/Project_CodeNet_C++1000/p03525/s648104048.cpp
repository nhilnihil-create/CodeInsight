#include <bits/stdc++.h>
using namespace std;
vector<int> D(24);

void f(int d)
{
  for (int i = 0; i <= 12; i++)
  {
    D[(d + i) % 24] = min(D[(d + i) % 24], i);
    D[(d - i + 24) % 24] = min(D[(d - i + 24) % 24], i);
  }
}

int solve(int N, vector<int> &vd)
{
  vector<int> v = {0, 24};
  for (int i = 0; i < N; i++)
  {
    if (D[vd[i]] == 0 && D[24 - vd[i]] == 0)
      return 0;
    if (D[vd[i]] > D[24 - vd[i]])
    {
      f(vd[i]);
      v.push_back(vd[i]);
    }
    else
    {
      f(24 - vd[i]);
      v.push_back(24 - vd[i]);
    }
  }
  sort(v.begin(), v.end());
  int ans = 24;
  for (int i = 1; i < v.size(); i++)
  {
    ans = min(ans, v[i] - v[i - 1]);
  }
  return ans;
}

int main()
{
  int N;
  cin >> N;
  vector<int> vd(N);
  for (int i = 0; i < 24; i++)
  {
    D[i] = min(24 - i, i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> vd[i];
  }
  sort(vd.begin(), vd.end());
  cout << solve(N, vd) << endl;
}