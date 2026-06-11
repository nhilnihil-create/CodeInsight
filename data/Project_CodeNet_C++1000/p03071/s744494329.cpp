#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int ans=0;
  if(a>=b){
    ans+=a;
    a--;
  }
  else{
    ans+=b;
    b--;
  }
  if(a>=b) {
    ans+=a;
  }
  else{
    ans+=b;
  }
  cout<<ans<<endl;
  return 0;
}