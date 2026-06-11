#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n;
  cin>>n;
  if(n%10==0){
    cout<<10<<endl;
    return 0;
  }
  int ans=0;
  while(n>=10){
    ans+=n%10;
    n-=n%10;
    n/=10;
  }ans+=n;
  cout<<ans<<endl;
  return 0;
}