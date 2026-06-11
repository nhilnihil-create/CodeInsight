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
  vector<int> ch(0);
  int i;
  int n = s.size();
  rep(i,n)
  {
    if(s[i] == 'A')
    {
      ch.emplace_back(1);
    }
    else if(s[i] == 'B' && i < n-1)
    {
      if(s[i+1] == 'C')
      {
        ch.emplace_back(0);
        i++;
      }
      else
      {
        ch.emplace_back(-1);
      }
    }
    else
    {
      ch.emplace_back(-1);
    }
  }
  int m = ch.size();
  int las0 = m-1;
  ll ans = 0;
  for(i=m-1;i>=0;i--)
  {
    if(ch[i] == -1)
    {
      las0 = i-1;
    }
    else if(ch[i] == 1)
    {
      int add = las0-i;
      ans += add;
      las0--;
    }
  }
  cout << ans << endl;
}

