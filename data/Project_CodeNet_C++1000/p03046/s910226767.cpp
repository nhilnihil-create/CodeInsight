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
  ll m,k;
  cin>>m>>k;
  if((1<<m)<=k){
    COUT(-1);
    return 0;
  }
  if(m==0){
    cout<<0<<" "<<0<<endl;
    return 0;
  }
  else if(m==1&&k==1){
    COUT(-1);
    return 0;
  }
  else if(m==1&&k==0){
    cout<<0<<" "<<0<<" "<<1<<" "<<1<<endl;
    return 0;
  }
  else{
    ll cu=0;
    vll a(1<<m);
    rep(i,sz(a)){
      a[i]=i;
    }
    rep(i,sz(a)){
      if(i==k) continue;
      cout<<a[i]<<" ";
    }
    cout<<k<<" ";
    for(int i=sz(a)-1;i>=0;i--){
      if(i==k) continue;
      cout<<a[i]<<" ";
    }
    cout<<k<<endl;
  }
}
