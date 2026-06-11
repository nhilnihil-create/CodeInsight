#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define REP(i,x,y) for(ll (i)=(x);(i)<(y);(i)++)
#define RREP(i,x,y) for(ll (i)=(x);(i)>=(y);(i)--)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define mt(x,y,z) mp(x,mp(y,z))
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define fst first
#define snd second
#define itm1 fst
#define itm2 snd.fst
#define itm3 snd.snd
#define sz(v) ((ll)v.size())
#define oo 200000000000
//#define EPS 1e-9
//#define pi acos(-1)
//#define MOD 999999999999999989
#define MAXN 999940960546LL
#define cot 20
//#define N 300005
//#define min -9042414321442
#define INF 1065435634
#define N1 900
typedef long double ld;
typedef  long long ll;
typedef short int si;
//typedef ll ll;
typedef pair<ll,ld> ii;
typedef vector<ii> vii;
typedef pair<ll,ii> tri;
typedef vector<ll> vi;

#define N 500001   
#define M 20
//#define cap 1000000000
//#define bas 100003

inline ll ma(ll a, ll b){ return ((a-b>0)? a:b);}
inline ll mi(ll a, ll b){return ((a-b>0)? b:a);}
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1<<" | ";
  __f(comma+1, args...);
}
#else
#define trace(...)
#endif

struct Dij{
  vii adj[N];
  ll dis[N],p[N];
  ll n;
  bool vis[N]={0};
  inline void go(ll ini,ll k){
    REP(i,0,n) dis[i]=MAXN;
    class priori{public: bool operator()(ii &p1, ii &p2) {return p1.snd>p2.snd;}};
    priority_queue<ii, vii, priori> pq;
    pq.push({ini,dis[ini]=1});
    while(!pq.empty()){
      ii cur=pq.top(); pq.pop();
      ll vi=cur.fst, w=cur.snd;
      ll t1=(vi*10)%k, t2=(vi+1)%k;
      if(dis[t1]>w) dis[t1]=w, pq.push({t1,w});
      if(dis[t2]-1>w) dis[t2]=w+1, pq.push({t2,w+1});
    }
  }
};

int main(){
  fastio;
  ll n; cin>>n;
  Dij dij; dij.n=n;
  dij.go(1,n);
  cout<<dij.dis[0]<<endl;
  return 0;
}