#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<char,int>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline void out(T a){ cout << a << '\n'; }
void YN(bool ok){if(ok) cout << "Yes" << endl; else cout << "No" << endl;}
//void YN(bool ok){if(ok) cout << "YES" << endl; else cout << "NO" << endl;}


const ll INF=1e18;
const int mx=200005;

class Segtree{
public:
    ll N=1;
    V<ll> dat;
    explicit Segtree(ll sz){
        while(N<sz) N*=2;
        dat.reserve(2*N);
        rep(i,2*N)dat[i]=0;
    }

    // Range Minimum Query -------------------------

    void min_init(){
        for(int i=0;i<N;i++)min_update(i,INF);
    }

    void min_update(ll k,ll a){
        k+=N-1;
        dat[k]=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }

    ll min_query(ll a,ll b,ll k,ll l,ll r){
        if(r<=a||b<=l)return INF;
        if(a<=l&&r<=b)return dat[k];
        ll m=(l+r)/2;
        ll u=min_query(a,b,2*k+1,l,m);
        ll v=min_query(a,b,2*k+2,m,r);
        return min(u,v);
    }

    ll get_min(ll l,ll r){
        return min_query(l,r,0,0,N);
    }

    //Range Maximum Query ---------------------------

    void max_init(){
        for(int i=0;i<N;i++)max_update(i,-INF);
    }

    void max_update(ll k,ll a){
        k+=N-1;
        dat[k]=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }

    ll max_query(ll a,ll b,ll k,ll l,ll r){
        if(r<=a||b<=l)return -INF;
        if(a<=l&&r<=b)return dat[k];
        ll m=(l+r)/2;
        ll u=max_query(a,b,2*k+1,l,m);
        ll v=max_query(a,b,2*k+2,m,r);
        return max(u,v);
    }

    ll get_max(ll l,ll r){
        return max_query(l,r,0,0,N);
    }

    //Range Sum Query -----------------------------

    void sum_update(ll k,ll a){
        k+=N-1;
        dat[k]+=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=(dat[2*k+1]+dat[2*k+2]);
        }
    }
    
    ll sum_query(ll a,ll b,ll k,ll l,ll r){
        if(r<=a||b<=l)return 0LL;
        if(a<=l&&r<=b)return dat[k];
        ll m=(l+r)/2;
        ll u=sum_query(a,b,2*k+1,l,m);
        ll v=sum_query(a,b,2*k+2,m,r);
        return (u+v);
    }

    ll get_sum(ll l,ll r){
        return sum_query(l,r,0,0,N);
    }

    //その他----------------------------------------
    /*
    ll unit(){
        return ;//単位元
    }
    ll calc(ll a,ll b){
        return ;//演算
    }
    void update(ll k,ll a){
        k+=N-1;
        dat[k]=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=calc(dat[2*k+1],dat[2*k+2]);
        }
    }
    ll query(ll a,ll b,ll k,ll l,ll r){
        if(r<=a||b<=l)return unit();
        if(a<=l&&r<=b)return dat[k];
        ll m=(l+r)/2;
        ll u=min_query(a,b,2*k+1,l,m);
        ll v=min_query(a,b,2*k+2,m,r);
        return calc(u,v);
    }
    */
};

ll dp[mx];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    V<ll> h(n),a(n);
    V<ll> rev(n+1);
    Segtree ST(n+1);
    rep(i,n){
        cin>>h[i];
        rev[h[i]]=i;
    }
    cinf(n,a);
    rep(i,n){
        ll tmp=ST.get_max(0,h[i]);
        if(tmp+a[i]>dp[i]){
            dp[i]=tmp+a[i];
            ST.max_update(h[i],dp[i]);
        }
    }
    ll ans=0;
    rep(i,n) chmax(ans,dp[i]);
    out(ans);
}