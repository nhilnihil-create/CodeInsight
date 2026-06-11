#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main(){
  ll n ;cin>>n ;
  vector<ll> A(n) ,B(n);
  ll suma=0 ;ll sumb =0 ;
  vector<ll> sa(n) ;
  rep(i,n) {
    cin>>A[i] ;
    suma+=A[i] ;
  }
  rep(i,n) {
    cin>>B[i] ;
    sumb+=B[i] ;
    sa[i]=A[i]-B[i] ;//0以上だけ
  }
   sort(sa.begin(),sa.end()) ;
   if(suma<sumb) cout<<-1<<endl ;
   else{
      ll ans=0 ;
      ll yoyu=suma-sumb ;
    rep(i,n){
      if(sa[i]<0) continue ;
      if(sa[i]<=yoyu) ans++ ;
      yoyu-=sa[i] ;
    }
   cout<<n-ans<<endl ;
   }
  return 0 ;
}