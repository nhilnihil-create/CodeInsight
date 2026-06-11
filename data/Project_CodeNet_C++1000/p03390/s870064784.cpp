#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define INF 1000000000
#define MOD 1000000007

int main(){
  int Q;
  cin>>Q;
  vector<ll> A(Q),B(Q);
  for(int i=0;i<Q;i++){
    cin>>A.at(i)>>B.at(i);
  }

  for(int i=0;i<Q;i++){
    ll a=min<ll>(A.at(i),B.at(i));
    ll b=max<ll>(A.at(i),B.at(i));
    if(a==b||b-a==1){
      cout<<2*(a-1)<<endl;
    }else{
      ll ans=0;
      ll left=a+1;
      ll right=b;
      while(left+1<right){
        ll center=(left+right)/2;
        if(center*center<a*b){
          left=center;
        }else{
          right=center;
        }
      }
      if(left*left<a*b){
        ans=min<ll>(2*(left-a-1),2*(b-left-1))+1;
      }
      left=a+1;
      right=b;
      while(left+1<right){
        ll x=(left+right)/2;
        if(x*(x+1)<a*b){
          left=x;
        }else{
          right=x;
        }
      }
      if(left*(left+1)<a*b){
        ans=max<ll>(ans,2*min<ll>(left-a,b-right));
      }
      cout<<2*(a-1)+1+ans<<endl;
    }
  }
}
