#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

//Be careful MOD=1e9+7
const int MAX = 510000;
vector<ll> fac(MAX),finv(MAX),inv(MAX),invsum(MAX+1);
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    rep2(i,2,MAX){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if (n<k) return 0;
    if (n<0||k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    COMinit();
    ll ans=0;
    invsum[0]=0;
    rep(i,MAX) invsum[i+1]=(invsum[i]+inv[i+1])%MOD;
    rep(i,N) ans=(ans+A[i]*fac[N]%MOD*((invsum[i+1]+invsum[N-i]-1)%MOD)%MOD)%MOD;
    cout << ans << endl;
}