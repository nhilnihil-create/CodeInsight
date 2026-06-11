#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif
  string s;

  cin>>s;
  int n=s.length();

  int ans=n;
  for(int i=1;i<n;i++)
  {
    if(s[i-1]!=s[i])ans=min(ans,max(i,n-i));
  }
  cout<<ans;
}