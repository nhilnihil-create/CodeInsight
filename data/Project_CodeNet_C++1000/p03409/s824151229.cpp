#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N;
  cin >> N;
  vector<pair<pair<int, int>, pair<int, string>>> point(2 * N);
  rep(i, 2 * N)
  {
    cin >> point[i].first.first >> point[i].first.second;

    if (i < N)
    {
      point[i].second.first = i;
      point[i].second.second = "r";
    }
    else
    {
      point[i].second.first = i - N;
      point[i].second.second = "b";
    }
  }
  sort(point.begin(), point.end());

  int ans = 0;
  vector<pair<int, int>> kouho;
  vector<bool> is_paired(N);

  rep(i, 2 * N)
  {
    if (point[i].second.second == "r")
      kouho.push_back(make_pair(point[i].first.second, point[i].second.first));
    else
    {
      sort(kouho.rbegin(), kouho.rend());
      rep(j, kouho.size())
      {
        if (!is_paired[kouho[j].second] && kouho[j].first < point[i].first.second)
        {
          is_paired[kouho[j].second] = true;
          ans++;
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}