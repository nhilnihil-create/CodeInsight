#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  string s, t, u;
  cin >> s;
  t = s;
  sort(t.begin(), t.end());

  for (char c = 'a'; c <= 'z'; ++c)
    u.push_back(c);

  string diff;
  std::set_difference(u.begin(), u.end(), t.begin(), t.end(), std::inserter(diff, diff.begin()));

  if (0 < diff.size())
    cout << s << diff.front() << endl;
  else
  {
    if (s == "zyxwvutsrqponmlkjihgfedcba")
      cout << -1 << endl;
    else
    {
      t = s;
      next_permutation(t.begin(), t.end());
      for (int i = 0; i < 26; ++i)
      {
        cout << t[i];
        if (t[i] != s[i])
        {
          cout << endl;
          break;
        }
      }
    }
  }
  
  return 0;
}
