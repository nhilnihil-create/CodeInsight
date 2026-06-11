#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t N,K;
  cin>>N>>K;
  if(K%2!=0){
  int64_t ans=N/K;
    ans=powl(ans,3);
    cout<<ans<<endl;
  }else{
  int64_t a=N/K;
    a=powl(a,3);
    int64_t b=(N+K/2)/K;
    b=powl(b,3);
    int64_t ans=a+b;
    cout<<ans<<endl;
  }
  
   return 0;
}