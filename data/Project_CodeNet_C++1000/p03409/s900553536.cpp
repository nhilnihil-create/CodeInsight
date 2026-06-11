#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> R(N), B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> R[i].first >> R[i].second;
  }
  for (int i = 0; i < N; i++)
  {
    cin >> B[i].first >> B[i].second;
  }
  sort(R.begin(), R.end());
  sort(B.begin(), B.end());
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    vector<pair<int, int>>::iterator itr = lower_bound(R.begin(), R.end(), B[i]);
    int max = -1;
    vector<pair<int, int>>::iterator pos;
    for (vector<pair<int, int>>::iterator j = R.begin(); j < itr; j++)
    {
      pair<int, int> p = *j;
      if (p.second > max && p.second < B[i].second)
      {
        max = p.second;
        pos = j;
      }
    }
    if (max != -1)
    {
      R.erase(pos);
      ans++;
    }
  }
  cout << ans << endl;
}