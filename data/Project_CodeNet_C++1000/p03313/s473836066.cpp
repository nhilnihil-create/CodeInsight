#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<double> Vec;
typedef vector<Vec> Mat;
typedef pair<ll,ll> P;
typedef pair<double,ll> Pd;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd>> Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-3;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod
#define CHECK cout<<"arrived"<<endl

ll N,K;
vec d;
vector<P> D;
const ll MAXN=(1<<19)+1;

ll memo[MAXN][2];

void Solve(ll x){
    if(memo[x][1]>=0) return;
    if(!x) {
        memo[x][0]=0;
        return;
    }
    vector<P> p;
    rep(i,N) if(x & (1<<i)){
        ll A=x-(1<<i);
        Solve(A);
        if(memo[A][0]>=0) p.pb(mp(d[memo[A][0]],memo[A][0]));
        if(memo[A][1]>=0) p.pb(mp(d[memo[A][1]],memo[A][1]));
    }
    p.pb(mp(d[x],x));
    sort(ALL(p));
    U_ERASE(p);
    reverse(ALL(p));
    rep(i,2) memo[x][i]=p[i].second;
    return;
}


int main(){
    cin>>N; K=(1<<N);
    rep(i,MAXN) rep(j,2) memo[i][j]=-1;
    rep(i,K) {
        ll x; cin>>x;
        d.pb(x);
    }
    vec ans(K,0);
    Solve(K-1);
    //REP(i,1,K) cout<<memo[i][0]<<' '<<memo[i][1]<<endl;
    REP(i,1,K) ans[i]=max(d[memo[i][0]]+d[memo[i][1]],ans[i-1]);
    REP(i,1,K) cout<<ans[i]<<endl;

}