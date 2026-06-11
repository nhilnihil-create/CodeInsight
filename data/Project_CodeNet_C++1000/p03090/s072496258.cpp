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
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main(){
  int n ;
  cin>> n ;
  if(n%2==1){
    int m=(n-1)*(n-1)/2 ;
    cout<< m<<endl ;
  rep2(i,1,n-1){
    rep2(j,i+1,n){
      if(i+j!=n)
      cout <<i<<" " <<j<< endl ;
    }
  }
  }
   else{
     int m=(n-2)*(n)/2;
    cout <<m<<endl ;
    rep2(i,1,n-1){
    rep2(j,i+1,n){
    if(i+j!=n+1)
     cout <<i<<" "<<j<<endl ;
    }
        }
    }
    return 0;
  }