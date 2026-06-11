#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
const int N=2e5+5;
set<int> g[N],s;
int a[N],b[N],u[N];
char c[N];
void ae(int x,int y){
    if(g[x].count(y))return;
    g[x].insert(y);
    if(c[y]=='A')a[x]++;
    if(c[y]=='B')b[x]++;
}
void chk(int x){
    if(!a[x]||!b[x])
        s.insert(x);
}
int tot;
void del(int x){
    tot--;
    u[x]=1;
    s.erase(x);
    for(int to:g[x]){
        if(to==x)continue;
        g[to].erase(x);
        if(c[x]=='A')--a[to];
        if(c[x]=='B')--b[to];
        chk(to);
    }
    g[x].clear();
}
int32_t main(){
    int n,m;
    cin>>n>>m;tot=n;
    forn(i,n)cin>>c[i+1];
    forn(i,m){
        int x,y;
        cin>>x>>y;
        ae(x,y);ae(y,x);
    }
    for(int i=1;i<=n;++i){
        if(!u[i]&&(!a[i]||!b[i]))del(i);
        while(!s.empty())del(*s.begin());
    }
    if(tot)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}