#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  string s;
  int K;
  cin >> s >> K;
  map<string, int> count;
  rep(num, 5)
  {
    rep(i, s.size() - num)
    {
      count[s.substr(i, num + 1)];
    }
  }

  int cnt = 1;
  for (pair<string, int> P : count)
  {
    if (cnt++ == K)
    {
      cout << P.first << endl;
      return 0;
    }
  }
  return 0;
}