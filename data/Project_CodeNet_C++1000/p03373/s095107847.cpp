#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int a,b,c,x,y;
  int ans=0;
  cin>>a>>b>>c>>x>>y;
  c*=2;
  ans=min(a+b,c)*min(x,y);
  if(x<y)ans+=min(b,c)*abs(x-y);
  else ans+=min(a,c)*abs(x-y);
  cout<<ans<<endl;
  return 0;
}