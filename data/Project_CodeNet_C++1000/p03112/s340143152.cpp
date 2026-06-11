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
  ll a,b,q;
  cin>>a>>b>>q;
  vll s(a),t(b),x(q);
  rep(i,a)cin>>s[i];
  rep(i,b) cin>>t[i];
  rep(i,q) cin>>x[i];
  sort(all(s));
  sort(all(t));
  ll ans=0;
  rep(i,q){
    ll cu=INF;
    vll k(2),u(2);
     k[0]=lower_bound(all(s),x[i])-s.begin()-1;
     k[1]=upper_bound(all(s),x[i])-s.begin();
     u[0]=lower_bound(all(t),x[i])-t.begin()-1;
     u[1]=upper_bound(all(t),x[i])-t.begin();
    rep(j,2){
      rep(r,2){
        if((j==0&&k[j]<0)||(j==1&&k[j]==a)||(r==0&&u[r]<0)||(r==1&&u[r]==b))continue;
      if(r!=j){
        ll w=max(abs(s[k[j]]-x[i]),abs(t[u[r]]-x[i]));
        ll e=min(abs(s[k[j]]-x[i]),abs(t[u[r]]-x[i]));
        cu=min(cu,2*e+w);
      }
        else cu=min(cu,max(abs(s[k[j]]-x[i]),abs(t[u[r]]-x[i])));
      }
    }
    COUT(cu);
  }
}