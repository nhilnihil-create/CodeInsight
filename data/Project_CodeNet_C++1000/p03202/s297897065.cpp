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

const int N=2e5+5,OO=1e18;
int a[N],p[N];
int n,mxp;
int g(int len){
    if(len>mxp)return OO;
    return p[len];
}
int f(vector<pii>&v){
    for(int i=sz(v)-1;i>=0;--i){
        ++v[i].s;
        if(v[i].s<g(v[i].f))return 1;
        v[i].s=0;
    }
    return 0;
}
int check(int m){
    p[0]=1;mxp=0;
    for(int i=1;i<=n;++i){
        p[i]=p[i-1]*m;
        mxp=i;
        if((double)p[i]*m>OO)break;
    }
    vector<pii> v;//{len,ord}
    v.pb(a[0],0);
    for(int i=1;i<n;++i){
        if(a[i]>a[i-1]){
            v.pb(a[i]-a[i-1],0);
        }else if(a[i]==a[i-1]){
            if(!f(v))return 0;
        }else{
            int d=a[i-1]-a[i];
            while(d-v.back().f>=0){
                d-=v.back().f;
                v.pop_back();
            }
            if(d){
                v.back().f-=d;
                v.back().s/=g(d);
            }
            if(!f(v))return 0;
        }
    }
    return 1;
}
int32_t main(){
    cin>>n;
    forn(i,n)cin>>a[i];
    int l=0,r=n;
    while(r-l>1){
        int m=(l+r)/2;
        if(check(m))r=m;
        else l=m;
    }
    cout<<r<<'\n';
    return 0;
}
