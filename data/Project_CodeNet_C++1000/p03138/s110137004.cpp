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
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(){
  ll n,k;
  cin>>n>>k;
  vll a(n);
  rep(i,n) cin>>a[i];
  vll b1(50);
  vll b0(50);
  sort(all(a));
  rep(i,n){
    bitset<50> g(a[i]);
    
    for(int j=0;j<50;j++){
      if(g.test(j)){
        b1[j]++;
      }
      else{
        b0[j]++;
      }
    }
  }
  ll bi=max(a[n-1],k);
  bitset<50> bb(bi);
  ll j=49;
  while(1){
    if(bb.test(j))break;
    j--;
  }
  bitset<50> kk(k);
  ll cu=1;
  ll ans=0;
  ll s=modpow(2,j,INF);
  for(int i=j;i>=0;i--){
    if(cu&&!kk.test(i)){
      ans+=b1[i]*s;
      s/=2;
    }
    else if(cu&&kk.test(i)){
      if(b1[i]>b0[i]){
        ans+=b1[i]*s;
        s/=2;
        cu=0;
      }
      else{
        ans+=b0[i]*s;
        s/=2;
      }
    }
    else{
      ans+=max(b1[i],b0[i])*s;
      s/=2;
    }
  }
  COUT(ans);
}