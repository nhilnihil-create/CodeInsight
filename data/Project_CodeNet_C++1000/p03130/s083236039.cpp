#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;

template <class T> using V = vector<T>;
template <class S, class T> using P = pair<S, T>;
template <class... T> using TP = tuple<T...>;

using ll = long long;
using db = double;
using ldb = long db;
using str = string;
using vll = V<ll>;
using vvll = V<V<ll>>;
using pll = P<ll,ll>;
using tpll = TP<ll,ll,ll>;
using vpll =V<pll>;
using vst = V<str>;
using vch = V<char>;

#define FOR(i,a,b) for(ll i=(a);i<(ll)(b);i++)
#define rFOR(i,a,b) for(ll i=(b);i>(ll)(a);i--)
#define oFOR(i,a,b) for(ll i=(a);i<(ll)(b);i+=2)
#define bgn begin()
#define en end()
#define SORT(a) sort((a).bgn,(a).en)
#define REV(a) reverse((a).bgn,(a).en)
#define fi first
#define se second
#define sz size()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) __lcm(a,b)
#define co(a) cout<<a<<endl
#define ci(a) cin>>a
#define pb(a) push_back(a)
#define pob pop_back()
#define mp make_pair
#define mt make_tuple
#define pbmp(a,b) push_back(mp(a,b))
#define subs(a,b) substr(a,b)
#define cfs(a) cout<<fixed<<setprecision(a)
#define INF 1e16
#define mod 1e9+7


int main() {
  vll v(6);
  FOR(i,0,6){
    cin>>v[i];
  }
//  bool a=false,b=false,c=false,d=false;
  vll count(4);
  FOR(i,0,6){
    if(v[i]==1) count[0]++;
    if(v[i]==2) count[1]++;
    if(v[i]==3) count[2]++;
    if(v[i]==4) count[3]++;
  }
  ll bns=1;
  FOR(i,0,4){
    bns*=count[i];
  }
  if(bns==4){
    co("YES");
  }
  else{
    co("NO");
  }
}
