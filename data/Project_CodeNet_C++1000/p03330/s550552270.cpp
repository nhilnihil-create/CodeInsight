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
typedef pair<double,double> PD;
typedef priority_queue<P,vector<P>,greater<P> > P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd> > Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-6;

#define _GLIBCXX_DEBUG
#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end())

void Add(ll &a, ll b){a=(a+b)%mod;}
void Pro(ll &a, ll b){a=(a*b)%mod;}

ll N,C;
ll D[31][31];
ll Count[31][3];

void input(){
    cin>>N>>C;
    rep(i,C) rep(j,C) cin>>D[i][j];
    rep(i,N) rep(k,N) {
        ll x; cin>>x; x--;
        Count[x][(i+k)%3]++;
    }
}

ll Solve(ll a, ll b, ll c){
    if(a==b) return INF;
    if(b==c) return INF;
    if(c==a) return INF;
    ll ret=0;
    rep(i,C) ret+=Count[i][0]*D[i][a];
    rep(i,C) ret+=Count[i][1]*D[i][b];
    rep(i,C) ret+=Count[i][2]*D[i][c];
    return ret;
}
int main(){
    input();
    ll ans=INF;
    rep(i,C) rep(j,C) rep(k,C) ans=min(ans,Solve(i,j,k));
    cout<<ans<<endl;
}