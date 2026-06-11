#
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  string s;
  cin >> s;
  
  int east[n] = {0}, west[n] = {0};
  if(s[0] == 'E') east[0] = 1;
  else west[0] = 1;
  for(int i = 1; i < n; i++)
  {
    if(s[i] == 'E')
    {
      east[i] = east[i-1] + 1;
      west[i] = west[i-1];
    }else
    {
      west[i] = west[i-1] + 1;
      east[i] = east[i-1];
    }
  }
    
  int ans = 0;
  int minans = east[n-1] - east[0];
  for(int i = 1; i < n; i++)
  {
    ans = west[i-1] + east[n-1] - east[i];
    minans = min(ans,minans);
  }
  
  cout << minans << endl;
}
