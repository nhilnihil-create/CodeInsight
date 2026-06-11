#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;
ll likemap[13];
int main(){
  cin>>N;
  if(24<=N)
    cout<<0<<endl;
  else{
    likemap[0]++;
  for(ll i=0;i<N;i++){
  ll a;cin>>a;likemap[a]++;
  }ll Max=0;
    for(ll i=0;i<13;i++)
      if(Max<likemap[i])Max=likemap[i];
    if(3<=Max)
      cout<<0<<endl;
    else{
    vector<ll>A;vector<ll>B;
      for(ll i=0;i<13;i++)
        if(likemap[i]==1){
        A.push_back(i);
        }else if(likemap[i]==2){
        B.push_back(i);B.push_back(24-i);
        }else{}
    ll M=A.size(); ll ans=0;
      for(ll bit=0;bit<(1<<M);bit++){
        ll Min=24;vector<ll>C=B;
        for(ll i=0;i<M;i++)
          if(bit & (1<<i)){
          C.push_back(A[i]);
           }else{
          C.push_back(24-A[i]);
          }ll SIZE=C.size();
        for(ll I=0;I<SIZE-1;I++)
          for(ll J=I+1;J<SIZE;J++){
            ll x=min(abs(C[I]-C[J]),(24-abs(C[I]-C[J])));
          if(x<Min)Min=x;
          }
               if(ans<Min)ans=Min;
      }cout<<ans<<endl;
    
    
    }
  
  }
  return 0;
}