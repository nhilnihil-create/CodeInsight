#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main()
{
  string s;
  cin >> s;
  if(s.size()==26){
    reverse(s.begin(), s.end());
    char now = s[0];
    int idx = 0;
    for (int i = 1; i <= s.size() - 1; i++)
    {
      if (s[i] > now)
      {
        idx++;
        now = s[i];
      }
      else
        break;
    }
    if (idx == 25)
    {
      cout << -1 << endl;
      return 0;
    }
    char mini = 'z';
    REP(i, idx + 1)
    {
      if (s[i] > s[idx + 1])
        mini = min(mini, s[i]);
    }
    reverse(s.begin(), s.end());
    REP(i, s.size() - idx - 2) cout << s[i];
    cout << mini << endl;
    return 0;
  }
  for (int i = 0; i < 26; i++)
  {
    char c = i + 'a';
    bool t = true;
    REP(j, s.size())
    {
      char a = s.at(j);
      if(a==c){
        t = false;
      }
    }
    if(t){
      cout << s << c << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}