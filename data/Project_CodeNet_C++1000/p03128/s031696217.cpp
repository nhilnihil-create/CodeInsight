#include <bits/stdc++.h>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static ll MOD=1e9+7;
ll max(ll a, ll b) {return a>b?a:b;}
ll min(ll a, ll b) {return a<b?a:b;}

ll co[]={INF, 2, 5, 5, 4, 5, 6, 3, 7, 6};
set<ll> match;
ll dp[10007];

void rec(ll hon, ll len) {
  if(len==0) return;
  
  ll t=0;
  for(auto m: match) {
    if(hon-co[m]<0) continue;
    
    if(dp[hon-co[m]]==len-1) t=m;
  }
  
  //pt(hon-co[t]);
  cout << t;
  rec(hon-co[t], len-1);
}

int main(void) {
  ll N, M;
  cin >> N >> M;
  ll a[MAX];
  ll i;
  ll f[10]={};
  
  for(i=0; i<M; i++)
    cin >> a[i];
  sort(a, a+M);
  reverse(a, a+M);
  
  for(i=0; i<M; i++) {
    if(f[co[a[i]]]) continue;
    
    match.insert(a[i]);
    f[co[a[i]]]=1;
    
  }
  
  for(i=1; i<=N; i++) dp[i]=-INF;
  dp[0]=0;
  
  for(i=0; i<N; i++) {
    if(dp[i]==-INF) continue;
    for(auto m: match) {
      chmax(dp[i+co[m]], dp[i]+1);
    }
  }
      
  rec(N, dp[N]);
  pt("");
  
}
