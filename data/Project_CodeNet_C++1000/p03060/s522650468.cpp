#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n), c(n);
  rep(i, n)
  {
    cin >> v.at(i);
  }
  rep(i, n)
  {
    cin >> c.at(i);
  }
  int ans = 0;
  int max = 0;
  for (int bit = 0; bit < (1 << n); bit++)
  {
    bitset<50> s(bit);
    rep(i, n)
    {
      if (s.test(i))
      {
        ans += (v.at(i) - c.at(i));
      }
    }
    if (max < ans)
    {
      max = ans;
    }
    ans = 0;
  }
  cout << max << endl;
}
