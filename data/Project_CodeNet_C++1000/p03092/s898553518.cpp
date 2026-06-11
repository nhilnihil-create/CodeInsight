#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb emplace_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
#define dupli(a) a.erase(unique(all(a)),a.end())
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vvvvi=vector<vvvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const ll INF=1001001001;
const ll mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void noyes(T b){if(b)out("no");else out("yes");}
template<class T> void NoYes(T b){if(b)out("No");else out("Yes");}
template<class T> void NOYES(T b){if(b)out("NO");else out("YES");}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
ll N=1;
vi segmi,lazy;
void init(vi v){
    while(N<v.size())N*=2;
    segmi=vi(N*2-1,inf);
    lazy=vi(N*2-1);
    rep(i,v.size())segmi[i+N-1]=v[i];
    for(int i=N-2;i>=0;i--)segmi[i]=min(segmi[i*2+1],segmi[i*2+2]);
}
void eval(int k,int l,int r){
    if(lazy[k]==0)return;
    segmi[k]+=lazy[k];
    if(r-l>1){
        lazy[k*2+1]+=lazy[k];
        lazy[k*2+2]+=lazy[k];
    }
    lazy[k]=0;
}
void add(int a,int b,int k,int l,int r,ll x){
    eval(k,l,r);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
        lazy[k]+=x;
        eval(k,l,r);
    }
    else{
        add(a,b,k*2+1,l,(l+r)/2,x);
        add(a,b,k*2+2,(l+r)/2,r,x);
        segmi[k]=min(segmi[k*2+1],segmi[k*2+2]);
    }
}
ll getmi(int a,int b,int k,int l,int r){
    eval(k,l,r);
    if(a<=l&&r<=b)return segmi[k];
    if(r<=a||b<=l)return inf;
    ll c1=getmi(a,b,k*2+1,l,(l+r)/2);
    ll c2=getmi(a,b,k*2+2,(l+r)/2,r);
    return min(c1,c2);
}
void update(ll i,ll x){
    ll t=getmi(i,i+1,0,0,N);
    add(i,i+1,0,0,N,x-t);
}
void solve(){
    ll n,l,r;cin>>n>>r>>l;
    vi dp(n);
    init(dp);
    rep(i,n){
        ll a;cin>>a;
        a--;
        update(a,getmi(0,a+1,0,0,N));
        add(0,a,0,0,N,r);
        add(a+1,N,0,0,N,l);
    }
    out(getmi(0,N,0,0,N));
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}