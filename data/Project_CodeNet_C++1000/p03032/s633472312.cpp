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
typedef priority_queue<P,vector<P>,greater<P> > P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd> > Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-8;


#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod

int main(){
    ll N,K; cin>>N>>K;
    vec d(N);
    rep(i,N) cin>>d[i];
    vec L(N+1,0), R(N+1,0);
    rep(i,N) L[i+1]=L[i]+d[i];
    for(int i=N-1;i>=0;i--) R[i]=R[i+1]+d[i];
    reverse(ALL(R));
    
    vec minus;
    ll ans=-INF;
    rep(i,N+1) {
        if(i>K) break;
        if(i>0) if(d[i-1]<0) minus.pb(d[i-1]);
        vec Min;
        rep(k,minus.size()) Min.pb(minus[k]);
        rep(j,N+1-i){
            if(i+j>K) break;
            ll X=L[i]+R[j], Y=K-i-j;
            if(j>0) if(d[N-j]<0) Min.pb(d[N-j]);
            sort(ALL(Min));
            rep(k,min(Y,(ll)Min.size())) X-=Min[k];
            //cout<<i<<' '<<j<<':'<<X<<endl;
            //rep(k,min(Y,(ll)Min.size())) cout<<Min[k]<<','<<endl;
            ans=max(ans,X); 
        }    
    }
    cout<<ans<<endl;
}