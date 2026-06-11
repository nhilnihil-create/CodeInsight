#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
using namespace std;

int main(){ 
  int a,b,c;
  cin>>a>>b>>c;
  int ans=0;
  if(c-a-b<=1) ans+=c;
  else ans+=a+b+1;
  ans+=b;
  co(ans);
  
  return 0;
}