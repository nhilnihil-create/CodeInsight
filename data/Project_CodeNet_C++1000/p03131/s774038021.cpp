#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll k,a,b;
  cin>>k>>a>>b;
  ll ans=0;
  if(b-a<=2 || k-a<=0){
    ans=k+1;
  }else{
    ans=a;
    if((k-a+1)%2==0){
      ans+=(b-a)*((k-a+1)/2);
    }else{
      ans+=(b-a)*((k-a+1)/2)+1;
    }
  }
  cout<<ans<<endl;
}