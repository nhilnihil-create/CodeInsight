#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  if(a+b<=c*2){
    cout<<a*x+b*y<<endl;
  }
  else{
    int d=min(x,y);
    int ans=c*d*2;
    x-=d;
    y-=d;
    if(a<=c*2){
      ans+=a*x;
    }
    else{
      ans+=c*x*2;
    }
    if(b<=c*2){
      ans+=b*y;
    }
    else{
      ans+=c*y*2;
    }
    cout<<ans<<endl;
  }
  return(0);
}
