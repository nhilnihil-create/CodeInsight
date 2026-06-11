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
// Union Find

template<typename T>
struct UnionFind
{
	vector<T> par;
	vector<T> rank;
	vector<T> sizes;
	UnionFind(T n):par(n),rank(n,0),sizes(n,1){
	   for(T i=0;i<n;i++){
	     par[i]=i;
	   }
	}
	T root(T x){
	  return par[x]==x?x:par[x]=root(par[x]);
	}

	bool unite(T x,T y){
	  if(x==y) return false;
	  x=root(x); y=root(y);
	  if(x==y) return false;
	  if(rank[x]<rank[y]) swap(x,y);
	  if(rank[x]==rank[y]) rank[x]++;
	  par[y]=x;
	  sizes[x]=sizes[x]+sizes[y];
	  return true;
	}
	bool same(T x,T y){
	  return root(x)==root(y);
	}
	T size(T x){
	  return sizes[root(x)];
	}
};
int main(){
  ll n,m;
  cin>>n>>m;
  UnionFind<ll> uf(n);
  rep(i,m){
    ll x,y,z;
    cin>>x>>y>>z;
    x--;
    y--;
    uf.unite(x,y);
  }
  set<ll> s;
  rep(i,n){
    s.insert(uf.root(i));
  }
  COUT(sz(s));
}