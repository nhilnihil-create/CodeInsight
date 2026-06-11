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
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin>>n;
  vi a(n);
  vi b(n);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];

  b.pb(llINF);
  ll ans=0;
  vi sum(100);
  for(int j=28;j>=0;j--){
    for(int i=0;i<n;i++)b[i]%=(1<<(j+1));
    sort(ALL(b));
    for(int i=0;i<n;i++){
      ll aa=(a[i]%(1<<(j+1)));
      ll cnt=0;
      auto lb=lower_bound(ALL(b),(1<<j)-aa);
      auto lb2=lower_bound(ALL(b),(1<<(j+1))-aa);
      cnt+=(lb2-lb);
      auto lb3=lower_bound(ALL(b),(1<<(j+1))+(1<<j)-aa);
      auto lb4=lower_bound(ALL(b),(1<<(j+1))+(1<<(j+1))-aa);
      cnt+=(lb4-lb3);
      sum[j]+=cnt;
    }
  }
  for(int i=0;i<=28;i++){
    ans+=(1<<i)*(sum[i]%2);
  }

  cout<<ans<<endl;
  return 0;
}
