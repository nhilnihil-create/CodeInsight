#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s,t;
  cin>>s>>t;
  int n = s.size();
  int m = t.size();
  
  if(n<m)
  {
    cout<<"UNRESTORABLE"<<endl;
    return 0;
  }
  bool ans = false;
  for(int i=n-m;i>=0;i--)
  {
    bool found = true;
    for(int j=0;j<m;j++)
    {
      if(s[i+j]=='?')
      {
        continue;
      }
      if(s[i+j]!=t[j])
      {
        found = false;
        break;
      }
    }
    if(found)
    {
      ans = true;
      for(int j=0;j<m;j++)
      {
        s[i+j] = t[j];
      }
      break;
    }
  }
  if(!ans)
  {
    cout<<"UNRESTORABLE"<<endl;
    return 0;
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      if(s[i]=='?')
      {
        s[i]='a';
      }
    }
    cout<<s<<endl;
    return 0;
  }
}
