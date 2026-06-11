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
  ll h,w,d;
  cin>>h>>w>>d;
  vector<pll> p(h*w);
  rep(i,h)rep(j,w) {
    ll a;
    cin>>a;
    a--;
    p[a]=mp(i+1,j+1);
  }
  vvll t(d,vll(1));
  vector<pll> f(d);
  rep(i,d){
    t[i][0]=p[i].F+p[i].S;
    f[i]=p[i];
  }
  rep(i,h*w){
    if(i<d) continue;
    t[i%d].pb(t[i%d][sz(t[i%d])-1]+(abs(f[i%d].F-p[i].F)+abs(f[i%d].S-p[i].S)));
    f[i%d]=p[i];
  }
  ll q;
  cin>>q;
  rep(i,q){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    ll a1=a/d;
    ll a2=a%d;
    ll b1=b/d;
    ll b2=b%d;
    COUT(t[b2][b1]-t[a2][a1]);
  }
}
