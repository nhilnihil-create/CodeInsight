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
ll fd(ll n){
  rep(i,51){
    if((1LL<<i)&n){
      return i;
    }
  }
}
ll ed(ll n){
  for(ll i=50;i>=0;i--){
    if((1LL<<i)&n){
      return i;
    }
  }
}
ll pa(ll n){
  ll res=1LL<<fd(n);
  for(ll i=fd(n)+1;i<=50;i++){
    if(i==ed(n))break;
    if(!((1LL<<i)&n)){
      res+=1LL<<i;
    }
  }
  return res;
}
ll r(ll n){
  for(ll i=50;i>=0;i--){
    if((1LL<<i)&n){
      return i+1;
    }
  }
}
int main(){
  ll n;
  cin>>n;
  map<ll,ll> p;
  vll a(n);
  rep(i,n){
    cin>>a[i];
    p[a[i]]++;
  }
  sort(rall(a));
  ll ans=0;
  rep(i,n){
    if(p[a[i]]==0)continue;
    if(p[(1LL<<r(a[i]))-a[i]]){
      if(((1LL<<r(a[i]))-a[i]==a[i])&&(p[(1LL<<r(a[i]))-a[i]]<2)) continue;
    ans++;
    p[(1LL<<r(a[i]))-a[i]]--;
    p[a[i]]--;
    }
  }
  COUT(ans);
}
