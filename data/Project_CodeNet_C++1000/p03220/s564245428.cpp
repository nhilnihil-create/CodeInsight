#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t,a,h,i,ans;
  double v=1000.0,w;
  cin>>n>>t>>a;
  for(i=1;i<=n;i++){
    cin>>h;
    w=abs(-0.006*h+t-a);
    if(w<v){
      v=w;
      ans=i;
    }
  }
  cout<<ans<<endl;
}