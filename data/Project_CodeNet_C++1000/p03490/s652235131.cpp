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

  int d[16010] ;
  int dd[16010] ;
  int e[16010] ;
  int ee[16010] ;
int main(){
  string s ; cin>> s ;
  ll x,y ; cin>>x>> y ;
  x+=8005 ;y+=8005 ;
  ll k= s.size() ;
  vector<ll> A, B ;
  ll yoko = 0 ;
  ll tate =0 ;
  bool ok= 1 ;
  rep(i,k){
    if(s[i]=='F'){
        if(ok) yoko++ ;
        else tate ++ ; 
    }
    else{
    if(yoko>0) A.pb(yoko) ;
    if(tate>0) B.pb(tate) ;
    yoko=0 ;tate=0 ;
    ok = 1-ok ;
    }
    if(i==k-1){
    if(yoko>0) A.pb(yoko) ;
    if(tate>0) B.pb(tate) ;     
    }
  }
 
 ll  p= A.size() ;
 ll  q= B.size() ;
  rep(i,16010){
      d[i]=0 ;
      e[i]=0 ;
      dd[i]=0 ;
      ee[i] =0 ;
  }
  d[8005]=1 ;
  e[8005]=1 ;
  rep(i,p){
    rep(j,16010){
        if(d[j]==1){
            ll xx= j+A[i] ;
             dd[xx]= 1 ;
            ll yy = j-A[i] ;
            if(i>0|| s[0]=='T') dd[yy]=1 ;
        }
    }
    rep(j,16010){
     d[j]=dd[j] ;
     dd[j]=0 ;
    }
  }

  rep(i,q){
    rep(j,16010){
        if(e[j]==1){
            ll xx= j-B[i] ;
            ll yy= j+B[i] ;
             ee[xx]= 1 ;
           ee[yy]=1 ;
        }
    }
    rep(j,16010){
       e[j]=ee[j] ;
       ee[j]=0 ;
    }
  }
  bool oko=1 ;
  if(d[x]==0) oko=0 ;
  if(e[y]==0) oko=0 ;
  if(oko) cout<<"Yes"<<endl ;
  else cout<< "No"<<endl ;
 return 0 ;
}
