#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using P = pair<ld,ld>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<v<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=998244353;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> F(N,0);
    for(ll i=0;i<N;++i){
        for(ll j=0;j<10;++j){
            ll f;
            cin >> f;
            F[i]+=f<<j;
        }
    }
    vector<vector<ll>> P(N, vector<ll>(11));
    for(ll i=0;i<N;++i)
        for(ll j=0;j<=10;++j){
            cin>>P[i][j];
        }
    ll ans=-INF;
    for(ll i=1;i<(1LL<<10);++i){
        ll benefit=0;
        for(ll j=0;j<N;++j)benefit+=P[j][__builtin_popcountll(i&F[j])];
        chmax(ans,benefit);
    }
    prt(ans)
    return 0;
}
