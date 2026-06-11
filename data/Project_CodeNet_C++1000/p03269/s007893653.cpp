#include <bits/stdc++.h>
using namespace std;
 
 
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
 
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
 
void solve(){
 
 
}

vector<pii > g[21];
vi c;
void dfs(int u){
    if(u==19) return;
    rep(i,sz(g[u])){
        int v=g[u][i].fst;
        //if(g[u][i].snd==-1) g[u][i].snd=i*c[u];
        c[v]+=c[u];
    }
    dfs(u+1);
}
void dfs2(int u){
    if(u==19) return;
    sort(all(g[u]));
    rep(i,sz(g[u])){
        if(g[u][i].fst==u+1) g[u][i].snd=i*c[u];
        else g[u][i].snd=c[g[u][i].fst]-1;
    }
    dfs2(u+1);
}


vi ans;
void chk(int u, int l){
   if(u==19) { ans.pb(l); return;}

   rep(i,sz(g[u])){
       chk(g[u][i].fst, l+g[u][i].snd);
   }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();

    ll l;cin>>l;
    vi v(30,0);
    int mx=-1;
    rep(i,21)if(l&(1<<i)) v[i]=1, mx=i;

    rep(i,mx) g[i].pb({i+1,-1}), g[i].pb({i+1,-1});
    repA(i,mx,18) g[i].pb({i+1,0});
    rep(i,mx)if(v[i]==1) g[0].pb({mx-i,-1});

    c.resize(25,0);
    c[0]=1;
    dfs(0);
    dfs2(0);

    int m=0;
    rep(i,21) m+=sz(g[i]);
    cout<<20<<' '<<m<<endl;
    rep(i,21)trav(it,g[i]) cout<<i+1<<' '<<it.fst+1<<' '<<it.snd<<endl;


    //chk(0, 0);
    //sort(all(ans));
    //debug(ans);

	return 0;
}
 

