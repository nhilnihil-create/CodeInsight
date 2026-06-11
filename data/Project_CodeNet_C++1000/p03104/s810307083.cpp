#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int MOD = 1000000007;
const int MAX = 510000;
ll f(ll x){
  if(x==0){return 0;}
  else if(x%2){
    if(((x+1)/2)%2){return 1;}
    else{return 0;}
  }
  else{return f(x-1)^x;}
}
int main(){
  ll a,b,ans=0;cin>>a>>b;
  cout<<(f(b)^f(a-1))<<endl;
}

