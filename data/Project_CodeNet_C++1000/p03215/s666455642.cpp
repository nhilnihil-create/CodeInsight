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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<ll> sum(N+1,0);
    rep(i,N) sum[i+1]=sum[i]+A[i];
    multiset<ll> s,dust;
    rep(i,N+1) rep2(j,i+1,N+1) s.insert(sum[j]-sum[i]);
    ll maxi=-1,ans=0,MAX=50;
    vector<ll> cnt(MAX,0);
    while(true){
        fill(all(cnt),0);
        bool ok=false;
        dust.clear();
        for (auto x:s){
            if (maxi!=-1&&!(x&1LL<<maxi)){
                dust.insert(x);
                continue;
            }
            rep(i,MAX) if (x&1LL<<i) ++cnt[i];
        }
        for (auto x:dust) s.erase(s.lower_bound(x));
        rep(i,MAX) if (cnt[i]>=K) maxi=i,ok=true;
        if (ok) ans|=1LL<<maxi,MAX=maxi;
        else break;
    }
    cout << ans << endl;
}