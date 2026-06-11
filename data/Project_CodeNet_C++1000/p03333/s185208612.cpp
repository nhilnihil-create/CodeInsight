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
const int N=1e5;
int a[N+N+1];
int b[N+N+1];
int32_t main(){
    int n;
    cin>>n;
    forn(i,n){
        int l,r;
        cin>>l>>r;
        a[l+N]++;
        b[r+N]++;
    }
    int ans=0,l=0,r=n;
    forn(i,N+N+1){
        r-=a[i];
        l+=b[i];
        // if(abs(i-N)<=7)dbg(i-N,l,r);
        if(i-N<0){
            if(l&&r){
                if(l<=r)ans+=l*2;
                else ans+=(r+1)*2;
            }else if(l)ans+=2;
        }else{
            if(l&&r){
                if(l>=r)ans+=r*2;
                else ans+=(l+1)*2;
            }else if(r)ans+=2;
        }
    }
    cout<<ans<<'\n';
    return 0;
}