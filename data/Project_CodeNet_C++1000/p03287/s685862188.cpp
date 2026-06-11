#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <numeric>
#include <cmath>
#include <cctype>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,x); REP(i,sizeof(a)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}


int main(){
  ll N,M; cin>>N>>M;
  ll cumu=0,a;
  map<ll,ll> mp;
  vector<ll> v;
  
  REP(i,N+1){
    if(i==0){
      cumu = 0;
    }else{
      cin >> a;
    }
    cumu += a;
    cumu %= M;
    ++mp[cumu];
    if(mp[cumu]==2){ v.push_back(cumu); }
  }
  ll ans = 0;
  for(ll amari:v){
    ll x = mp[amari];
    ans += x*(x-1)/2;
  }
  cout << ans <<"\n";
  
}