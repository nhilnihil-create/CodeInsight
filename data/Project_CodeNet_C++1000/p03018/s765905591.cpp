#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  string s;
  cin>>s;
  ll n=s.length(),ans=0,v=0,i=0;
  for(ll i=0;i<n;i++)
  {
    if(s[i]=='A')
    {
      v++;
    }
    else
    {
      int q=0;
      if(i<n-1&&s[i]=='B'&&s[i+1]=='C')
      {
        i++;
        ans=ans+v;
      }
      else
       v=0;
    }
  }
  cout<<ans<<endl;
}
