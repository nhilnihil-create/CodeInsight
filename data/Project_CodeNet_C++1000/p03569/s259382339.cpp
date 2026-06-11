#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;

  string t;
  rep(i, s.length()) {
    if(s[i]!='x') t+= s[i];
  }

  string u(t);
  reverse(u.begin(), u.end());

  if(u!=t) {
    cout << -1 << endl;
    return 0;
  }

  int res = 0;
  int m = 0, n = s.length()-1;
  while( n - m >= 1 ) {
    //printf("s[%d]:%c vs s[%d]:%c\n", m, s[m], n, s[n]);                                
    if(s[m] != s[n]) {
      if(s[n] == 'x') n--;
      if(s[m] == 'x') m++;
      res++;
    }
    else { n--; m++; }
  }

  cout << res << endl;
}
