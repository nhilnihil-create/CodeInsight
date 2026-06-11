#include<bits/stdc++.h>
using namespace std;
#define ll                          long long
#define in(a)                       ll a; cin>>a;
#define in2(a,b)                    ll a,b; cin>>a>>b;
#define in3(a,b,c)                  ll a,b,c; cin>>a>>b>>c;
#define in4(a,b,c,d)                ll a,b,c,d; cin>>a>>b>>c>>d;
#define in5(a,b,c,d,e)              ll a,b,c,d,e; cin>>a>>b>>c>>d>>e;
#define lelo(b)                     for(auto &i:b)cin>>i;
#define ff                          first
#define ss                          second
#define call(v)                     v.begin(),v.end()
#define rall(v)                     v.rbegin(),v.rend()
#define show(x)                     for(auto t:x)cout<<t<<" ";
#define pb                          push_back
#define bhar(s,v)                   memset(s,v,sizeof(s))
#define endl                        "\n"                       
#define ce(x)                       cout<<x<<"\n";
#define nl                          cout<<endl;
#define jaldi                       ios_base::sync_with_stdio(false);cin.tie(NULL);
#define dekh_lo                     ce("dekh_lo");
#define sz(x)                       (ll)x.size()
#define re                          return

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef pair<ll,ll> pii;
typedef vector<pii> vii;
typedef vector<ll> vi;

const ll mod=1e9+7;
const ll N=4e5+5;
ll i,j;

/*


*/
vi dp(N,0);
std::vector<bool> vis(N,0);
vi adj[N];
ll dfs(ll x){
	if(vis[x]){
		re dp[x];
	}
	vis[x]=1;
	ll ans=0;
	for(auto next:adj[x]){
		ans=max(ans,dfs(next)+1);
	}
	re dp[x]=ans;
}
void solve(){
    in2(n,m);
    for(i=0;i<m;i++){
    	in2(x,y);
    	adj[x].pb(y);
    }
    ll ans=0;
    for(i=1;i<=n;i++){
    	ans=max(ans,dfs(i));
    }
    ce(ans);
}

int32_t main(){
    // jaldi
    ll t; 
    // cin>>t;
    t=1;     
    while(t--){
        solve();
    }
}

/*


*/

  