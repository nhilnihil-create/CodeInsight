#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  int n;
  cin >> n;
  cin >> s;
  string a, b;
  int ans = 0, x, y, p;
  for(int i = 1; i < n - 2; i++) {
    a = s.substr(0, i);
    b = s.substr(i);
    p = 0;
    for(char c = 'a'; c <= 'z'; c++) {
      x = 0;
   	  y = 0;
      rep(j, i) if(a[j] == c) x++;
      rep(j, n - i) if(b[j] == c) y++;
      if(x && y) p++;
    }
    ans = max(ans, p);
  }
  cout << ans << endl;
      
    
  return 0;
}