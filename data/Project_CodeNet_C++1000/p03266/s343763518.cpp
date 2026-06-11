#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

int main(){
  ll N,K;
  cin>>N>>K;
  if(K==1){
    cout<<N*N*N<<endl;
  }else if(K%2==1){
    ll x=N/K;
    cout<<x*x*x<<endl;
  }else{
    ll x=N/K;
    ll y=N/(K/2)-x;
    cout<<x*x*x+y*y*y<<endl;
  }
}
