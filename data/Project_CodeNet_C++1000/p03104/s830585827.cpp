#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second 
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
 ll a,b ;cin>>a>>b ;
 a-- ; 
 ll bd= b/2 ; ll ad= a/2 ;
 ll c= 0 ;ll d= 0 ;
 if(b%2==0){
     if((bd)%2==0) d= b ;
     else d= b^1;
      }
 else{
     if((bd+1)%2==0) d= 0 ;
     else d= 1 ;
 }
 if(a==-1) cout<<d<<endl ;
 else{
     if(a%2==0) {
         if(ad%2==0) c= a ;
         else c= a^1 ;
         }
     else{
         if((ad+1)%2==0) c=0 ;
         else c=1 ;
     }
     ll ans= c^d ;
     cout<< ans <<endl ; 
 } 

 return 0 ; 
}