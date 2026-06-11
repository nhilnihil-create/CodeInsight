#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;
const int mod = 1000000007;

int main()
{
  string s;
  cin >> s;
  int ans = 0;
  rep(i, 3)
  {
    if (s.at(i) == '1')
    {
      ans++;
    }
  }
  cout << ans << endl;
}
