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

ll ruijou(ll n, ll k){
    if(k==0) return 1;
    ll x=k/2;
    long long t=ruijou(n,x);
    t=(t*t)%mod;
    if(k%2==1) return (n*t)%mod;
    else return t%mod;
}

ll N;
vec y,d;
ll Solve(ll X){
    vec count(4,0);
    ll ret=0;
    ll x=X;
    rep(j,N) {
        count[x%4]+=d[j];
        if(x%4!=3) ret+=10;
        x/=4;
    }
    if(count[0]==0 || count[1]==0 || count[2]==0) return INF;
    
    rep(i,3) ret+=abs(count[i]-y[i]);
    //cout<<count[0]<<' '<<count[1]<<' '<<count[2]<<':'<<ret-30<<endl;
    return ret-30;

}


int main(){
    cin>>N;
    rep(i,3){
        ll x; cin>>x;
        y.pb(x);
    }
    
    rep(i,N) {
        ll x; cin>>x;
        d.pb(x);
    }
    ll MAXN=ruijou(4,N);
    //cout<<MAXN<<endl;
    ll ans=INF;
    rep(i,MAXN)ans=min(ans,Solve(i));
    cout<<ans<<endl;

}