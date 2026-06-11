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
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

const int MAX_WS=2e4+10;

struct block{ll w,s,v;};
bool cmp(const block &a,const block &b){
    return a.w+a.s!=b.w+b.s?a.w+a.s<b.w+b.s:a.s<b.s;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<block> bs(N);
    rep(i,N){
        ll w,s,v; cin >> w >> s >> v;
        bs[i]=block{w,s,v};
    }
    sort(all(bs),cmp);
    vector<vector<ll>> dp(N+1,vector<ll>(MAX_WS,0));
    rep(i,N) rep(j,MAX_WS){
        chmax(dp[i+1][j],dp[i][j]);
        if (j<=bs[i].s) chmax(dp[i+1][j+bs[i].w],dp[i][j]+bs[i].v);
    }
    ll ans=0;
    rep(j,MAX_WS) chmax(ans,dp[N][j]);
    cout << ans << endl;
}