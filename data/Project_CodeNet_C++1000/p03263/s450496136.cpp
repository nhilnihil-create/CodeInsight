#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int h, w;
  cin >> h >> w;
  vector< vector<int> > a( h, vector<int>(w) );
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < w; ++j)
    {
      cin >> a[i][j];
    }
  }

  int cnt = 0;
  vector<string> ans;
  for(int i = 0; i < h; ++i)
  {
    for(int j = 0; j < w; ++j)
    {
      if(a[i][j] & 1)
      {
        if (j < w - 1)
        {
          cnt++;
          a[i][j + 1]++;
          stringstream ss;
          ss << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << endl;
          ans.emplace_back(ss.str());
        }
        else if (i < h - 1)
        {
          cnt++;
          a[i + 1][j]++;
          stringstream ss;
          ss << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << endl;
          ans.emplace_back(ss.str());
        }
      }
    }
  }

  cout << cnt << endl;
  for(const auto& s : ans) cout << s;
}

int main()
{
  fastio;
  solve();

  return 0;
}