#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  ll a,b,k;
  cin>>a>>b>>k;
  if(b-a+1<2*k){Rep(i,a,b+1)cout<<i<<endl;}
  else{rep(i,k)cout<<i+a<<endl;
    rep(i,k)cout<<b-k+i+1<<endl;
  }
    
    
  return 0;
}
