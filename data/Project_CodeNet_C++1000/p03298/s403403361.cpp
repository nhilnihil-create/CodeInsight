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
string s;
int n;
vector<pair<string,string> >cl;
map<pair<string,string>,ll>MP;
void dfs(int now,int depth,ll bit){
  if(depth==n){
    string red="";
    string blue="";
    if(now){
      for(int i=n;i<2*n;i++){
	if(bit&(1<<(i-n))){
	  red+=s[i];
	}else{
	  blue+=s[i];
	}	
      }
      reverse(ALL(blue));
      reverse(ALL(red));
      MP[mp(blue,red)]++;
    }else{
      for(int i=0;i<n;i++){
	if(bit&(1<<i))
	  red+=s[i];
	else
	  blue+=s[i];
      }
      cl.pb(mp(red,blue));
    
    }
    return;
  }
  dfs(now,depth+1,bit+(1<<depth));
  dfs(now,depth+1,bit);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  cin>>s;
  dfs(0,0,0);
  dfs(n,0,0);
  ll ans=0;
  for(int i=0;i<cl.size();i++){
    ans+=MP[cl[i]];
  }
  cout<<ans<<endl;
  return 0;
}
