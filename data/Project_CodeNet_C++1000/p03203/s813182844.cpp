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
vector<int> a[N];
int32_t main(){
    int h,w,n;
    cin>>h>>w>>n;
    forn(i,n){
        int x,y;
        cin>>x>>y;
        a[y].pb(x);
    }
    for(int i=1;i<=w;++i)sort(a[i].begin(), a[i].end());
    int x=1,y=1,ans=h,cur=0;
    while(1){
        int pos=upper_bound(a[y].begin(), a[y].end(),x)-a[y].begin();
        int d=h+1;
        if(pos<sz(a[y]))d=a[y][pos];
        upn(ans,cur+d-x);
        if(x+1==d)break;
        x++;
        cur++;
        if(y<w){
            pos=lower_bound(a[y+1].begin(), a[y+1].end(),x)-a[y+1].begin();
            if(pos==sz(a[y+1])||a[y+1][pos]!=x){
                y++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}

