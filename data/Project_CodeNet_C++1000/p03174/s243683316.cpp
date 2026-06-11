#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld pi=3.141592653589793238;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<vector<ll>> a(N, vector<ll>(N, 0));
    for(ll i=0;i<N;++i)
        for(ll j=0;j<N;++j)cin>>a[i][j];
    //dp[x][S]は男xまでを女の集合S内でマッチングさせる方法の数
    vector<vector<ll>> dp(N, vector<ll>(1LL<<N, -1));
    function<ll(ll,ll)> F=[&](ll x, ll S){
        if(x==-1)return 1LL;
        if(dp[x][S]!=-1)return dp[x][S];
        ll ret=0;
        for(ll i=0;i<N;++i){
            if((S&(1LL<<i))&&a[x][i]){
                ret+=F(x-1,S-(1LL<<i));
                ret%=MOD;
            }
        }
        return dp[x][S]=ret;
    };
    prt(F(N-1,(1LL<<N)-1))


    return 0;
}
