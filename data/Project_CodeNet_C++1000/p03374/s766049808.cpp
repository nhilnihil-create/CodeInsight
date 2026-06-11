 #include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main() {
  ll n,c ;
  cin >> n>>c ;
  vector<ll> x(n);
  vector<ll> v(n);
  rep(i,n) cin >>x[i] >>v[i] ;
  //利益の最大右回り
  vector<ll> rieki(n) ;
  rep(i,n){
    if(i==0) rieki[i] = v[0]-x[0] ;
    else 
    rieki[i]=rieki[i-1]+x[i-1]+v[i]-x[i] ;
  }
  vector<ll> rmax(n) ;
  rep(i,n){
    if(i==0) rmax[i] =rieki[i] ;
    else rmax[i] =max(rmax[i-1],rieki[i]) ;
  }
  //利益の最大左回り　 
  ll sum =0 ;
  rep(i,n) sum += v[i]  ;
  vector <ll> lieki(n) ;
  rep(i,n) lieki[i] = sum -c +v[i]-rieki[i] ;
  vector<ll> lmax(n) ;
  rep(i,n){
  if(i==0) lmax[n-1] =lieki[n-1];
  else lmax[n-1-i] = max(lmax[n-i],lieki[n-1-i]) ;
  } 
   ll rans =0ll ;
  rep2(i,1,n-1){
   rans =max(rans, rmax[i-1]+lieki[i]-(c-x[i])) ;
  }
  ll lans = 0ll;
  rep2(i,0,n-2){
    lans =max(lans ,rieki[i]-x[i]+lmax[i+1]) ;
  }
  ll ans=max(0ll,max(lans,max(rans,max(rmax[n-1],lmax[0])))) ;
   cout<< ans<< endl;
    return 0;
}