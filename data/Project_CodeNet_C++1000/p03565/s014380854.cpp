#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
  string s, t;
  cin >> s;
  cin >> t;
  vector<string> candi;
  for (int i = 0; i <= int(s.length() - t.length()); i++)
  {
    bool equal_check = true;
    rep(j, t.length())
    {
      if (s[i + j] != '?' && s[i + j] != t[j])
      {
        equal_check = false;
      }
    }
    if (equal_check)
    {
      string tmp;
      rep(j, s.length())
      {
        if (j >= i && j < (i + int(t.length())))
        {
          tmp.push_back(t[j - i]);
        }
        else
        {
          if (s[j] == '?')
          {
            tmp.push_back('a');
          }
          else
          {
            tmp.push_back(s[j]);
          }
        }
      }
      candi.push_back(tmp);
    }
  }
  if (candi.empty())
  {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  sort(candi.begin(), candi.end());
  cout << candi[0] << endl;
  return 0;
}