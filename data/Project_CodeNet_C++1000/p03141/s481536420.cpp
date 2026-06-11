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
 int n ;
 cin>> n ;
 vector<ll> A(n) ;
 vector<ll> B(n) ;
 vector<ll> wa(n) ; 
  rep(i,n){
    cin>>A[i]>>B[i] ;
    wa[i]=A[i]+B[i] ;
  }  
   vector<P> wawa(n) ;
   rep(i,n){
    wawa[i] = make_pair(wa[i],i) ; 
   }
  sort(wawa.rbegin(),wawa.rend()) ;
  ll sente=0 ;
  for(ll i=0;2*i<n;i++){
    sente+= A[wawa[i*2].second] ;
  }
  ll gote=0 ;
  for(ll i=0;2*i+1<n;i++){
    gote+=B[wawa[i*2+1].second] ;
  } 
    cout<< sente-gote<<endl;
    return 0;
  }