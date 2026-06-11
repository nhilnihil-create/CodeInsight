#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,i,j,k,ans=0;
  cin>>a>>b>>c>>x;
  x/=50;
  for(i=0;i<=a;i++) for(j=0;j<=b;j++) for(k=0;k<=c;k++) if(10*i+2*j+k==x) ans++;
  cout<<ans<<endl;
}