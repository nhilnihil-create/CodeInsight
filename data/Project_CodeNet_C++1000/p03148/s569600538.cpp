#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<pll> vpl;

#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define ZERO(a) memset(a,0,sizeof(a))

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k;
  cin>>n>>k;
  vpl t(n);
  REP(i,n)cin>>t[i].SE>>t[i].FI;

  sort(ALL(t), greater<pll>());
  vll picked(n+1), remind, tail;

  ll sum=0;
  ll kind=0;
  REP(i,n){
    if(i<k){
      sum+=t[i].FI;
      if(picked[t[i].SE]==0){
        picked[t[i].SE]=1;
        kind++;
      }
      else
        tail.push_back(t[i].FI);
    }
    else{
      if(picked[t[i].SE]==0){
        remind.push_back(t[i].FI);
        picked[t[i].SE]=1;
      }
    }
  }

  sort(ALL(tail));
  sort(ALL(remind), greater<ll>());
  ll ans = sum+kind*kind;
  ll m=min(tail.size(), remind.size());
  REP1(i,m)tail[i]+=tail[i-1];
  REP1(i,m)remind[i]+=remind[i-1];

  REP(i,m)
    ans = max(ans,sum-tail[i]+remind[i]+(kind+1+i)*(kind+1+i));

  cout<<ans<<endl;

}

