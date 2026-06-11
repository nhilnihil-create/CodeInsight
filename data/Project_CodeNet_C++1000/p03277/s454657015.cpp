#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
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
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const int INF=1001001001;
const int mod=998244353;
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
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}

vi seg,seg2;
ll N=1,N2=1;
void init(ll n){
    while(N<n)N*=2;
    seg=vi(N*2-1);
    rep(i,n)seg[i+N-1]=1;
    for(int i=N-2;i>=0;i--)seg[i]=seg[i*2+1]+seg[i*2+2];
}
void update(ll i){
    i=N+i-1;
    seg[i]=0;
    while(i>0){
        i=(i-1)/2;
        seg[i]=seg[i*2+1]+seg[i*2+2];
    }
}
ll getsum(ll a,ll b,ll k,ll l,ll r){
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b)return seg[k];
    ll c1=getsum(a,b,k*2+1,l,(l+r)/2);
    ll c2=getsum(a,b,k*2+2,(l+r)/2,r);
    return c1+c2;
}
void init2(ll n){
    while(N2<n)N2*=2;
    seg2=vi(N2*2-1);
    rep(i,n)seg2[i+N2-1]=1;
    for(int i=N2-2;i>=0;i--)seg2[i]=seg2[i*2+1]+seg2[i*2+2];
}
void update2(ll i){
    i=N2+i-1;
    seg2[i]=0;
    while(i>0){
        i=(i-1)/2;
        seg2[i]=seg2[i*2+1]+seg2[i*2+2];
    }
}
ll getsum2(ll a,ll b,ll k,ll l,ll r){
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b)return seg2[k];
    ll c1=getsum2(a,b,k*2+1,l,(l+r)/2);
    ll c2=getsum2(a,b,k*2+2,(l+r)/2,r);
    return c1+c2;
}
int main(){
    ll n;cin>>n;
    vi v(n);
    rep(i,n)cin>>v[i];
    ll ng=INF,ok=0;
    while(ng-ok>1){
        ll md=(ok+ng)/2;
        ll cnt=0;
        vi c(n);rep(i,n)if(v[i]>=md)c[i]++;
        ll sum=0;
        vp a,b;
        rep(i,n){
            sum+=c[i];
            if(i&1)a.eb(sum-i/2,i);
            else b.eb(sum-i/2,i);
        }
        sort(all(a));sort(all(b));
        vp id(n);
        rep(i,a.size())id[a[i].se]=P(i,0);
        rep(i,b.size())id[b[i].se]=P(i,1);
        init(a.size());init2(b.size());
        ll d=1,e=1;
        rep(i,n){
            cnt+=getsum2(lb(b,P(d,-inf)),N,0,0,N);
            cnt+=getsum(lb(a,P(e,-inf)),N,0,0,N);
            if(c[i]){
                d++;e++;
            }
            if(i&1)e--;
            else d--;
            if(id[i].se)update2(id[i].fi);
            else update(id[i].fi);
        }
        /*outv(seg);
        out(md);
        out(cnt);*/
        if(cnt>=(n*(n+1)/2+1)/2)ok=md;
        else ng=md;
    }
    out(ok);
}