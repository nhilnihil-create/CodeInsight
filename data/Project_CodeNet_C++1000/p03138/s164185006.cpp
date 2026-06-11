#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
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
#define sz(x) (ll)(x).size()
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
template<class T> inline bool chmax(T& a, T b) { 
 if (a < b) { a = b; return true; } return false; 
}
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
ll dp[60][2];
int main(){
  memset(dp,-1,sizeof(dp));
  ll n,k;
  cin>>n>>k;
  vll a(n);
  rep(i,n) cin>>a[i];
  dp[0][0]=0;
  rep(i,50)rep(j,2){
    if(dp[i][j]==-1) continue;
    ll num=0;
    ll mask=1LL<<(50-i-1);
    rep(r,n){
      if(a[r]&mask) num++;
    }
    ll cost0=mask*num;
    ll cost1=mask*(n-num);
    if(j==0){
      if(k&mask){
        dp[i+1][0]=max(dp[i+1][0],dp[i][j]+cost1);
        dp[i+1][1]=max(dp[i+1][1],dp[i][j]+cost0);
      }
      else{
        dp[i+1][0]=max(dp[i+1][0],dp[i][j]+cost0);
      }
    }
    if(j==1){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]+max(cost1,cost0));
    }
  }
  COUT(max(dp[50][0],dp[50][1]));
}
