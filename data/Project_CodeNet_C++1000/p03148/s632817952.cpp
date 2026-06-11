#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<"\n"
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define mp make_pair
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
int main(){
  ll n,k;
  cin>>n>>k;
  vll ans(1,0);
  vector<pll> a(n);
  vector<pll> b(n);
  rep(i,n){
    ll t,d;
    cin>>t>>d;
    b[i]=mp(t,d);
    a[i]=mp(d,t);
  }
  sort(rall(b));  
  PQR que;
  vector<pll> c(n);
  c[0]=mp(b[0].S,1);
  for(int i=1;i<n;i++){
    if(b[i].F==b[i-1].F){
      c[i]=mp(b[i].S,0);
    }
    else{
      c[i]=mp(b[i].S,1);
    }
  }
  sort(rall(c));
  vector<ll> e(0);
  for(int i=k;i<n;i++){
    if(c[i].S){
      e.pb(c[i].F);
    }
  }
  
  ll res=0;
  rep(i,k){
    if(c[i].S)res++;
    else que.pu(c[i].F);
    ans[0]+=c[i].F;
  }
  ans[0]+=res*res;
  sort(rall(e));
  rep(i,sz(e)){
    if(sz(que)==0) break;
    ll rr=ans[i];
    rr-=que.top();
    que.pop();
    rr-=res*res;
    res++;
    rr+=res*res;
    rr+=e[i];
    ans.pb(rr);
  }
  sort(rall(ans));
  COUT(ans[0]);
}
