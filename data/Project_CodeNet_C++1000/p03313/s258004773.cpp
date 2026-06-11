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
const int B=18,N=1<<B,OO=1e9;
pii mx[N][2];
int a[N];
void f(int i,pii v){
    forn(j,2)if(mx[i][j].s==v.s)return;
    upx(mx[i][1],v);
    if(mx[i][0]<mx[i][1])swap(mx[i][0],mx[i][1]);
}
int32_t main(){
    int b;cin>>b;
    int n=1<<b;
    forn(i,n){
        cin>>a[i];
        mx[i][0]={a[i],i};
        mx[i][1]={-OO,-1};
    }
    forn(i,n){
        forn(j,b){
            if(i>>j&1){
                int t=i^(1<<j);
                forn(k,2)f(i,mx[t][k]);
            }
        }
    }
    for(int k=1;k<n;++k){
        int ans=mx[k][0].f+mx[k][1].f;
        forn(j,b){
            if(k>>j&1){
                int s=k^(1<<j);
                int z=(1<<j)-1;
                s|=z;
                upx(ans,mx[s][0].f+mx[s][1].f);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}