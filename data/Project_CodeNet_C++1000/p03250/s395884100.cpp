#include<bits/stdc++.h>
using namespace std ;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int mx=max(a,max(b,c));
  int s=a+b+c;
  int ans=9*mx+s;
  cout<<ans<<endl;
return 0;
}
