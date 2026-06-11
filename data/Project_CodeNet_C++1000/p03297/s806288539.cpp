#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <deque>
using namespace std;
using ll=long long;
#define INF 2100000000

ll gcd(ll A,ll B){
  while(A%B!=0){
    ll tmp=A%B;
    A=B;
    B=tmp;
  }
  return B;
}

int main(){
  int T;
  cin>>T;
  vector<ll> a(T),b(T),c(T),d(T);
  for(int i=0;i<T;i++){
    cin>>a.at(i)>>b.at(i)>>c.at(i)>>d.at(i);
  }

  for(int i=0;i<T;i++){
    ll A=a.at(i);
    ll B=b.at(i);
    ll C=c.at(i);
    ll D=d.at(i);
    if(B>D){
      cout<<"No"<<endl;
    }else if(B==D){
      if(A<B){
        cout<<"No"<<endl;
        continue;
      }
      ll x=A%B;
      ll y=C/B;
      ll A=(y+2)*B+x;
      while(A>C){
        A-=B;
      }
      if(A<0){
        cout<<"No"<<endl;
      }else{
        cout<<"Yes"<<endl;
      }
    }else{
      if(A<B){
        cout<<"No"<<endl;
        continue;
      }else if(A<=D){
        ll x=D-B;
        ll y=(D-A)/x;
        A+=x*(y+1);
      }
      ll x=A%B;
      ll y=C/B;
      ll A=y*B+x;
      if(A>C){
        A-=B;
      }
      ll g=gcd(B,D);
      A+=((C-A)/g+1)*g;
      if(A-B>=0){
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
    }
  }
}
