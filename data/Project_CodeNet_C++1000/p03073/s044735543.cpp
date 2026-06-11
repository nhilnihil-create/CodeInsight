#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s;
  cin >> s;
  
  int n = s.size();
  int ans = 0;
  for(int i = 1; i < n; i++)
  {
    if(s[i] == s[i-1])
    {
      if(s[i-1] == '0') s[i] = '1';
      else              s[i] = '0';
      ans++;
    }
  }
  
  int com = 0;
  if(s[0] == '0') s[0] = '1';
  else            s[0] = '0';
  for(int i = 1; i < n; i++)
  {
    if(s[i] == s[i-1])
    {
      if(s[i-1] == '0') s[i] = '1';
      else              s[i] = '0';
      com++;
    }
  }
    
  cout << min(ans,com) << endl;
}
