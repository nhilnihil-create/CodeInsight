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
  ll n;
  cin>>n;
  vll a(13);
  a[0]++;
  rep(i,n){
    ll d;
    cin>>d;
    a[d]++;
    if(a[d]>=3) {
      COUT(0);
      return 0;
    }
  }
  if(a[0]>=2||a[12]>=2){
    COUT(0);
    return 0;
  }
  ll ans=0;
  for(int bit=0;bit<(1<<11);bit++){
    vll u(0);
    if(a[0]) u.pb(0);
    if(a[12]) u.pb(12);
    for(int i=0;i<11;i++){
      if(a[i+1]==2){
        u.pb(i+1);
        u.pb(24-i-1);
      }
      if(a[i+1]==1){
        if(bit&(1<<i)){
          u.pb(i+1);
        }
        else{
          u.pb(24-i-1);
        }
      }
    }
    sort(all(u));
    ll cu=INF;
    for(int i=1;i<sz(u);i++){
      cu=min(u[i]-u[i-1],cu);
    }
    cu=min(cu,min(u[sz(u)-1]-u[0],24-u[sz(u)-1]+u[0]));
    ans=max(ans,cu);
  }
  COUT(ans);
}