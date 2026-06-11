#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll max3(ll x,ll y,ll z){
  ll max;
  if(x>y){
    max=x;
  }else{
    max=y;
  }
  if(max<z){
    max=z;
  }
  return max;
}
int main(void){
  ll a,b,c,ans;
  cin>>a>>b>>c;
  ll max=max3(a,b,c);
  max*=3;
  ll sum=a+b+c;
  if((max%2)==(sum%2)){
    ans=(max-sum)/2;
  }else{
    ans=(max-sum+3)/2;
  }
  cout<<ans<<endl;
  return 0;
}