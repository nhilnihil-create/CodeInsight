#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  string s;
  cin >> s;
  int i;
  int n = s.size();
  string not_x = "";
  rep(i,n)
  {
    if(s[i] != 'x') not_x += s[i];
  }
  string rev_nx = not_x;
  reverse(all(rev_nx));
  if(rev_nx != not_x) cout << -1 << endl;
  else
  {
    int m = not_x.size();
    vector<int> adds(m+1,0);
    int next = 0;
    rep(i,n)
    {
      if(s[i] == not_x[next])
      {
        next++;
      }
      else
      {
        adds[next]++;
      }
    }
    int ans = 0;
    rep(i,m/2+1)
    {
      ans += 2*max(adds[i], adds[m-i]);
      ans -= (adds[i] + adds[m-i]);
    }
    cout << ans << endl;
  }
  
}

