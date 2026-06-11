#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

ll gcd(ll A,ll B){
  while(A%B!=0){
    ll tmp=A%B;
    A=B;
    B=tmp;
  }
  return B;
}

int main(){
  ll N,M;
  string S,T;
  cin>>N>>M>>S>>T;
  ll x=gcd(N,M);
  ll length=N*M/x;
  bool flag=true;
  for(int i=0;i<x;i++){
    if(S.at(N/x*i)!=T.at(M/x*i)){
      flag=false;
      break;
    }
  }
  if(flag){
    cout<<length<<endl;
  }else{
    cout<<-1<<endl;
  }
}
