#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
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
  ll n,k,q;cin>>n>>k>>q;
  vi A(n);
  ll ans=llINF;
  for(auto &a:A)cin>>a;
  for(int i=0;i<n;i++){
    vi ansvec;
    vi tmp;
    for(int j=0;j<n;j++){
      if(A[j]<A[i]){
	if(tmp.size()>=k){
	  sort(ALL(tmp));
	  for(int ii=0;ii<tmp.size()-k+1;ii++)
	    ansvec.pb(tmp[ii]);
	}
	tmp.clear();
      }else{
	tmp.pb(A[j]);
      }
    }
    if(tmp.size()>=k){
      sort(ALL(tmp));
      for(int j=0;j<tmp.size()-k+1;j++)
	ansvec.pb(tmp[j]);
    }
    if(ansvec.size()>=q){
      sort(ALL(ansvec));
      //cout<<ansvec[q-1]<<" "<<ansvec[0]<<endl;
      ans=min(ans,ansvec[q-1]-ansvec[0]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
