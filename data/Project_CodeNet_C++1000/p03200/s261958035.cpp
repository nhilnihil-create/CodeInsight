#include<bits/stdc++.h>
#define ll long long
#define mod (ll)(1e9+7)
using namespace std;
const int maxn =2e5+5;
char m[maxn];
int main()
{

  cin>>m;
  ll ans=0,k=0;
  for(ll i=0;m[i]!='\0';i++)
  {
      if(m[i]=='B')
        k++;
      else
        ans+=k;
  }
  cout<<ans<<endl;

    return 0;
}
