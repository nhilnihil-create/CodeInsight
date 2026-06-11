#include<bits/stdc++.h>
//using namespace std;
#define rep(i,j,n) for(ll i=(ll)(j);i<(ll)(n);i++)
#define REP(i,j,n) for(ll i=(ll)(j);i<=(ll)(n);i++)
#define per(i,j,n) for(ll i=(ll)(j);(ll)(n)<=i;i--)
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(ll)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(ll)(key)))
#define pb push_back
#define mp std::make_pair
#define endl "\n"
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi=vector<ll>;
using vii=vector<vi>;
using pii=std::pair<ll,ll>;
const ll MOD=1e9+7;
//const ll MOD=998244353;
//const ll MOD=100000;
const ll MAX=1e7;
const ll INF=(1ll<<60);
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
/*struct Binary_indexed_tree{
    int N;
    vi bit;
    Binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    void add(int x,int a){
        for(x;x<=N;x+=(x&-x)) bit[x]+=a;
    }
    ll sum(int x){
        ll ret=0;
        for(x;x>0;x-=(x&-x)) ret+=bit[x];
        return ret;
    }
};
struct Union_Find{
    ll N;
    vi par;
    vi siz;
    Union_Find(int n):N(n){
        par.resize(N);
        siz.resize(N,1);
        rep(i,0,N) par[i]=i;
    }
    ll root(ll X){
        if(par[X]==X) return X;
        return par[X]=root(par[X]);
    }
    bool same(ll X,ll Y){
        return root(X)==root(Y);
    }
    void unite(ll X,ll Y){
        X=root(X);
        Y=root(Y);
        if(X==Y) return;
        par[X]=Y;
        siz[Y]+=siz[X];
        siz[X]=0;
    }
};
ll modpow(ll X,ll Y){
    ll sum=X,cnt=1;
    vi A;
    while(cnt<=Y){
        A.pb(sum);
        sum*=sum;
        sum%=MOD;
        cnt*=2;
    }
    int M=A.size();
    ll ret=1;
    REP(i,1,M){
        if(Y>=(1ll<<M-i)){
            Y-=(1ll<<M-i);
            ret*=A[M-i];
            ret%=MOD;
        }
    }
    return ret;
}
ll fac[MAX],finv[MAX],inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(ll n,ll r){
    if(n<r||n<0||r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}*/
signed main(){
    ll N; cin>>N;
    ll M=(1ll<<N);
    vi A(M);
    rep(i,0,M) cin>>A[i];
    vii memo(N+1);
    vector<pii> max(M),second(M);
    vi sum(M);
    rep(i,0,M) memo[__builtin_popcountll(i)].pb(i);
    rep(i,0,N){
        rep(j,0,memo[i].size()){
            ll X=memo[i][j];
            if(second[X].first<A[X]) second[X]=mp(A[X],X);
            if(second[X]>max[X]) std::swap(second[X],max[X]);
            sum[X]=max[X].first+second[X].first;
            rep(k,0,N){
                ll Y=X|(1ll<<k);
                if(X!=Y){
                    vector<pii> B={second[X],second[Y],max[X],max[Y]};
                    sort(ALL(B));
                    max[Y]=B[3];
                    second[Y]=B[2];
                    if(max[Y]==second[Y]) second[Y]=B[1];
                }
            }
        }
    }
    second[M-1]=std::max(second[M-1],mp(A[M-1],M-1));
    sum[M-1]=second[M-1].first+max[M-1].first;
    rep(i,1,M){
        sum[i]=std::max(sum[i],sum[i-1]);
        cout<<sum[i]<<endl;
    }
}
