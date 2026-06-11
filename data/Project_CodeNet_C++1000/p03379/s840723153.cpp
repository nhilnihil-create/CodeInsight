#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
int main(){
  ll n;cin>>n;
  vector<ll> x(n),y(n);
  rep(i,n){
    cin>>x[i];
    y[i]=x[i];;
  }
  sort(y.begin(),y.end());
  ll j=x.size()/2;
  rep(i,n){
    ll k=x[i];
    if(k<y[j])cout<<y[j]<<endl;
    else cout<<y[j-1]<<endl;
  }

}