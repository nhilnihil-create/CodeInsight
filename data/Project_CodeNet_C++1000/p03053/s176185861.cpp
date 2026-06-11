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
 ll h ,w ;cin>>h>>w ;
 char d[h][w] ;
 queue<P> q ;
 ll dist[h][w] ;
 ll cnt =0 ;
 rep(i,h){
   rep(j,w) {
     cin>> d[i][j];
    if(d[i][j]=='#') {
     dist[i][j] =0 ;
     q.push(mpa(i,j)) ;
    }else cnt++ ;
    }
 }
  ll ans= 0;
  ll dx[] = {1, -1, 0, 0};
	ll dy[] = {0, 0, -1, 1};
  while(cnt>0){
  
  while(!q.empty()){
    P now=q.front() ;
  q.pop() ;
  ll a=now.first ;
  ll b=now.second ;
    rep(i,4){
     
     ll nowx= a+dx[i];
     ll nowy= b+dy[i] ;
    if (nowx < 0 ||nowx >= h || nowy < 0 || nowy >= w)
					continue;
    if(d[nowx][nowy]=='.') {
      q.push(mpa(nowx,nowy) ) ;
      d[nowx][nowy]='#' ;
      dist[nowx][nowy] =dist[a][b]+1 ;
        ans=dist[nowx][nowy] ;
            cnt-- ;
    }

    }
  }
  
  }

 cout<<ans<<endl;
  return 0;
  }