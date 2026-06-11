#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int a,b;
  int ans=0;
  cin>>a>>b;
  rep(i,2){
    if(a>=b){
      ans+=a;
      a--;
    }else{
      ans+=b;
      b--;
    }
  }
  cout<<ans<<endl;
  return 0;
}