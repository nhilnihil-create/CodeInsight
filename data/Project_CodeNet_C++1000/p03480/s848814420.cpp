#include <bits/stdc++.h>
using namespace std;
string s,sr;

int main()
{
  cin >> s;
  sr = s;
  int l = s.length();
  reverse(sr.begin(), sr.end());
  int res = (l+1) / 2;
  for (int i = (l+1) / 2; i < l; i++) {
    if (s[i] == sr[i] && s[i] == s[l/2]) {
      res++;
    } else {
      break;
    }
  }
  cout << res << endl;
}
