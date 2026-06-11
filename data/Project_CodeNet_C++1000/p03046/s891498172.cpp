#include <bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  ll m,k;
  cin >> m >> k;
  ll x=1;
  rep(i,m)x*=2;  
  if(m==0 || m==1){
    if(m==0 && k==0){
      cout << 0 << ' ' << 0 << endl;
    }
    else if(m==1 && k==0){
      cout << 0 << ' ' << 0 << ' ' << 1 << ' ' << 1 << endl;
    }else{
      cout << -1 << endl;
    }
    return 0;
  }
  if(k>=x){
    cout << -1 << endl;
    return 0;
  }
  for(ll i=x-1;i>=0;i--){
    if(i!=k)cout << i << ' ';
  }
  cout << k << ' ';
  for(ll i=0;i<x;i++){
    if(i!=k)cout << i << ' ';
  }
  cout << k << endl;
return 0;}