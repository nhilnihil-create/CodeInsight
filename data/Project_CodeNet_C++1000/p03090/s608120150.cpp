#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> ans;
  if (N % 2 == 1)
  {
    rep(i, N - 1)
    {
      for (int j = i + 1; j < N - 1; j++)
      {
        if (j == N - 2 - i)
          continue;
        ans.push_back(make_pair(i + 1, j + 1));
      }
    }
    rep(i, N - 1)
    {
      ans.push_back(make_pair(i + 1, N));
    }
  }
  else
  {
    rep(i, N)
    {
      for (int j = i + 1; j < N; j++)
      {
        if (j == N - 1 - i)
          continue;
        ans.push_back(make_pair(i + 1, j + 1));
      }
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size())
  {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}