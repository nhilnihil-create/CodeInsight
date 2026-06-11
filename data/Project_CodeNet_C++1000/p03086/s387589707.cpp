#include <bits/stdc++.h>
#include <set>
#include <queue>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define reps(i, s, n) for (int i = s; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++) 
#define repsl(i, s, n) for (ll i = s; i < (ll)(n); i++)  
#define outdeb(fir, sec, thr) cout << fir << ":" << sec << ":" << thr << endl

int main()
{
  string s;
  cin >> s;

  int maxv = 0;
  int cntv = 0;
  rep(i, s.size())
  {
    if(s[i] == 'A'
    || s[i] == 'G'
    || s[i] == 'C'
    || s[i] == 'T')
    {
      cntv++;
      maxv = max(maxv, cntv);
    }
    else
    {
      cntv = 0;
    }
    
  }

  cout << fixed << maxv << endl;

  return 0;
}