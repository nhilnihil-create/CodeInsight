#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;
ll max(ll a, ll b) {return a>b?a:b;}
ll min(ll a, ll b) {return a<b?a:b;}

ll N, Q;
string s;
char t[MAX*2], d[MAX*2];

//左から脱落するなら1を返す
ll LC(ll u) {
  for(ll i=0; i<Q; i++) {
    if(t[i]==s[u]) {
      if(d[i]=='L') u--;
      if(d[i]=='R') u++;
      
      if(u<0) return 1;
      if(u>=N) return 0;
    }
  }
  
  return 0;
}

//右から脱落するなら1を返す
ll RC(ll u) {
  for(ll i=0; i<Q; i++) {
    if(t[i]==s[u]) {
      if(d[i]=='L') u--;
      if(d[i]=='R') u++;
      
      if(u<0) return 0;
      if(u>=N) return 1;
    }
  }
  
  return 0;
}

int main(void) {
  cin >> N >> Q;
  cin >> s;
  ll i;
  
  for(i=0; i<Q; i++) {
    cin >> t[i] >> d[i];
  }
  
  ll lan=0, ran=0;
  
  ll l=0, r=N;
  while(l+1<r) {
    ll mid=(l+r)/2;
    if(LC(mid)) l=mid;
    else r=mid;
  }
  lan=l;
  
  l=0; r=N;
  while(l+1<r) {
    ll mid=(l+r)/2;
    if(RC(mid)) r=mid;
    else l=mid;
  }
  ran=r;
  
  pt(max(0, ran-lan-1));
  
}
