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
  int d,n ;cin>>d>>n ;
  if(d==0&&n==100)cout<<101<<endl ;
  else if(d==1&&n==100) cout<<10100<<endl ; 
  else if(d==2&&n==100) cout<<1010000<<endl ; 
   else cout<<pow(100,d)*n<<endl ;  
   return 0 ;
}