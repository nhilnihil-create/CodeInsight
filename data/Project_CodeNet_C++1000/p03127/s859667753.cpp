#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll N,minimum=1000000000;
  cin>>N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin>>A.at(i);
    minimum=min(minimum,A.at(i));
  }
  while(true){
    ll x=minimum,check=0,count=0;
    for(ll i=0;i<N;i++){
      if(A.at(i)!=x || check>0){A.at(i)=A.at(i)%x;}
      if(A.at(i)==x){check++;}
      if(A.at(i)==0){count++;}
      else{minimum=min(minimum,A.at(i));}
    }
    if(count==N-1){break;}
  }
  cout<<minimum<<endl;
}