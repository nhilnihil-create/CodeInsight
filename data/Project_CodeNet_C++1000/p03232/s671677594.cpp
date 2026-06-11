#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define bit_cnt(n) (__builtin_popcountll(n))
#define substr(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{ll x,y,t;};
struct Edge{ll to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=201010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(ll from,ll to,ll cost){E[from].pb({to,cost});}
};
ll binpow(ll x, ll e,ll d=1) {//もともとの数,MOD-2
  ll ret = d, p = x;
  while(e > 0) {
    if(e%2 == 0) {p = p*p%MOD; e /= 2;}
    else {ret = ret*p%MOD; e--;}
  }
  return ret;
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(n);
  for(int i=0;i<n;i++)cin>>A[i];
  ll fact = 1;
  for(int i=0;i<n;i++){fact*=(i+1);fact%=MOD;}
  ll rui[n+10]={};
  for(int i=0;i<n;i++){
    rui[i+1]=(rui[i]+(fact*binpow(i+1,MOD-2))%MOD)%MOD;
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    ll hoge=rui[i+1];
    hoge%=MOD;
    hoge+=(rui[n-i]-rui[1]+MOD)%MOD;
    hoge%=MOD;
    ans+=A[i]*hoge%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}
