#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if(a%b==0){
    return b;
  }else{
    return gcd(b,a%b);
  }
}
int main(void){
  int n,a,ans;
  cin>>n>>ans;
  for(int i=0;i<n-1;i++){
    cin>>a;
    ans=gcd(max(a,ans),min(a,ans));
  }
  cout<<ans<<endl;
  return 0;
}