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
const ll INF = 1LL << 62;
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
  ll n,k;
  cin>>n>>k;
  vll x(n),y(n);
  rep(i,n) cin>>x[i]>>y[i];
  ll ans=INF;
  rep(i,n){
    for(int j=i+1;j<n;j++){
      ll ii=i;
      ll jj=j;
      rep(o,n){
        for(int p=o+1;p<n;p++){
          ll oo=o;
          ll pp=p;
          ll xx=0;
      for(int u=0;u<n;u++){
        if(x[ii]<x[jj]) swap(ii,jj);
        if(y[oo]<y[pp]) swap(oo,pp);
        if(x[ii]>=x[u]&&x[jj]<=x[u]){
          if(y[oo]>=y[u]&&y[pp]<=y[u])xx++;
        }
      }

      if(xx>=k){
        ans=min(ans,abs(x[ii]-x[jj])*abs(y[oo]-y[pp]));
      }
        }
      }
    }
  }
  COUT(ans);
}