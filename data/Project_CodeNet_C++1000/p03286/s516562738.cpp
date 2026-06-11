#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int INF=1e9;
ll devine(ll x,ll y){
  if(x<0&&y<0){
    if(x%y<0){return (x/y)+1;}
  }
  return x/y;
}
ll amari(ll x,ll y){
  if(x<0&&y<0){
    if(x%y<0){return (x%y)-y;}
  }
  return x%y;
}
int main(){
  ll n,x;
  cin>>n;
  vll bit(0);
  if(n==0){cout<<0<<endl;}
  else{
    while(n!=0){
      x=amari(n,-2);
      n=devine(n,-2);
      bit.push_back(x);
    }
    for(int i=bit.size();i>0;i--){
      cout<<bit[i-1];
    }
    cout<<endl;
  }
}