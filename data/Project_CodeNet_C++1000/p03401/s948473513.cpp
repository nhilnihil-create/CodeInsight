#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nature(ll a){
  return max(a,-1*a);
}
int main(){
  ll N,sumprice;
  cin>>N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin>>A.at(i);
    if(i==0){sumprice=nature(A.at(0));}
    if(i>0){sumprice+=nature(A.at(i)-A.at(i-1));}
    if(i==N-1){sumprice+=nature(A.at(N-1));}
  }
  ll memo=sumprice;
  for(ll i=0;i<N;i++){
    if(i==0){sumprice+=nature(A.at(1))-nature(A.at(0))-nature(A.at(1)-A.at(0));}
    else if(i==N-1){sumprice+=nature(A.at(N-2))-nature(A.at(N-1))-nature(A.at(N-2)-A.at(N-1));}
    else{sumprice+=nature(A.at(i+1)-A.at(i-1))-nature(A.at(i)-A.at(i-1))-nature(A.at(i)-A.at(i+1));}
    cout<<sumprice<<endl;
    sumprice=memo;
  }
}