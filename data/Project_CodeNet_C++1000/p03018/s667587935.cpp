#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  
  ll res = 0, cnt = 0;
  rep(i, n-1)
  {
    if(s[i] == 'A')
    {
      cnt++;
      //continue;
    }
    else if(s[i] == 'B' && s[i+1] == 'C')
    {
      res += cnt;
      i++;
    }
    else
    {
      cnt = 0;
    }
  }
  cout << res << endl;
  
  return 0;
}