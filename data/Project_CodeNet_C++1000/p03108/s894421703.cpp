#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};


const ll MAXN=100001;
ll par[MAXN];
ll rnk[MAXN];
ll Size[MAXN];

void shoki(){
    for(ll i=0;i<MAXN;i++) {par[i]=i; rnk[i]=0; Size[i]=1;}
}

ll sch(ll x){
    if(par[x]==x) return x;
    else return par[x]=sch(par[x]);
}

ll con(ll A,ll B){
    A=sch(A);
    B=sch(B);
    if(A==B) return 0;
    if(rnk[A]>rnk[B]) swap(A,B);
    ll aa=Size[A], bb=Size[B];
    par[A]=B;
    Size[B]+=Size[A];
    Size[A]=Size[B];
    if(rnk[A]==rnk[B]) rnk[B]++;

    return aa*bb;
}

ll is_size(ll k){
    return Size[sch(k)];
}

bool same(ll A,ll B){
    return sch(A)==sch(B);
}

int main(){
    shoki();
    ll N,M; cin>>N>>M;
    vector<P> d;
    rep(i,M){
        ll a,b; cin>>a>>b;
        d.pb(mp(a,b));
    }
    vec ans(M+1, N*(N-1)/2);
    reverse(ALL(d));
    rep(i,M) ans[i+1]=ans[i]-con(d[i].first,d[i].second);
    reverse(ALL(ans));
    REP(i,1,M+1) cout<<ans[i]<<endl;
}