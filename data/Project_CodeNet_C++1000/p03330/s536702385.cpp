#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define mp make_pair
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define sz(x) (int)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
using vc = vector<char>;
using vvc = vector<vc>;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n,c;
  cin>>n>>c;
  vvll d(c,vll(c));
  vvll t(n,vll(n));
  rep(i,c){
    rep(j,c){
      cin>>d[i][j];
    }
  }
  rep(i,n){
    rep(j,n){
      cin>>t[i][j];
    }
  }
  vvll y(3,vll(c));
  rep(i,n){
    rep(j,n){
      ll u=(i+j+2)%3;
      y[u][t[i][j]-1]++;
    }
  }
  ll ans=INF;
  for(int i=0;i<c;i++){
    for(int j=0;j<c;j++){
      for(int u=0;u<c;u++){
        if(i==j||i==u||j==u){
          continue;
        }
        ll cu=0;
        
        rep(q,c){
          if(q==i)continue;
          if(y[0][q]){
            cu+=d[q][i]*y[0][q];
          }
        }
        rep(q,c){
          if(q==j)continue;
          if(y[1][q]){
            cu+=d[q][j]*y[1][q];
          }
        }
        rep(q,c){
          if(q==u)continue;
          if(y[2][q]){
            cu+=d[q][u]*y[2][q];
          }
        }
        ans=min(ans,cu);
      }
    }
  }
  COUT(ans);
}
