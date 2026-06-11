#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  string s;cin>>s;
  int i,j;
  if(s.size()==26)
  {
    bool ok=false;
    vector<char> suf(0);
    suf.emplace_back(s[25]);
    for(i=24;i>=0;i--)
    {
      if(s[i]<s[i+1])
      {
        char k=s[i+1];
        rep(j,suf.size())
        {
          if(suf[j]>s[i]&&suf[j]<k)
          {
            k=suf[j];
          }
        }
        cout<<s.substr(0,i)<<k<<endl;
        ok=true;
        break;
      }
      suf.emplace_back(s[i]);
    }
    if(!ok)cout<<-1<<endl;
  }
  else
  {
    char c;
    for(c='a';c<='z';c++)
    {
      bool used=false;
      rep(i,s.size())
      {
        if(s[i]==c)used=true;
      }
      if(used)continue;
      cout<<s<<c<<endl;
      break;
    }
  }
}
