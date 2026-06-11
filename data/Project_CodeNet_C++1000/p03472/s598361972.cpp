#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll N,H;
  cin >> N >> H;
  vP p(N),q(N);
  rep(i,N){
    cin >> p[i].first >> p[i].second;//pについてはたくさん・域
    q[i].second=p[i].first;
    q[i].first=p[i].second;//qについては一回、たくさん
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  sort(q.begin(),q.end());
  reverse(q.begin(),q.end());
  bool B=true;
  ll i=0;
  ll ans=0;
  ll d=0;
  while(p[0].first<q[i].first&&H>0){
    H-=q[i].first;
    i++;
    ans++;
  }
  if(H>0){
    ans+=(H-1)/p[0].first+1;
  }
  cout << ans << endl;
}