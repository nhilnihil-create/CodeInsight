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
    vector<ll> C(N-1,0);
    vector<ll> S(N-1,0);
    vector<ll> F(N-1,0);
    for(ll i=0;i<N-1;++i)cin>>C[i]>>S[i]>>F[i];
    for(ll i=0;i<N;++i){
        ll time=0;
        for(ll j=i;j<N-1;++j){
            //timeをS[j]以上で最小のF[i]の倍数にする
            time=max(F[j]*((time+F[j]-1)/F[j]),S[j]);
            time+=C[j];
        }
        prt(time)
    }
    return 0;
}
