#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define min(a,b) ((a>b)? b:a)
#define max(a,b) ((a>b)? a:b)
int main()
{
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  if(2*c>=a+b){
    cout<<x*a+b*y;
    return 0;
  }
  ll ans=min(x,y)*2*c;
  if(max(x,y)==x){
    ans+=(max(x,y)-min(x,y))*min(a,2*c);
  }
  else ans+=(max(x,y)-min(x,y))*min(b,2*c);
  cout<<ans;
}