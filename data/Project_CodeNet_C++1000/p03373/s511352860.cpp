#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y,ans;
  cin>>a>>b>>c>>x>>y;
  
  if(x>=y){
    ans=min(2*x*c,2*y*c+(x-y)*a);}
  if(x<y){
    ans=min(2*y*c,2*x*c+(y-x)*b);}
  
  ans=min(ans,a*x+b*y);
  
  cout<<ans;}