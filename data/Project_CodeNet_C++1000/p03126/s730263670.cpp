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


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> A(M+1,0);
    for(ll i=0;i<N;++i){
        ll K;
        cin >> K;
        for(ll j=0;j<K;++j){
            ll a;
            cin >> a;
            A[a]++;
        }
    }
    ll ans=0;
    for(ll i=1;i<=M;++i){
        if(A[i]==N)ans++;
    }
    prt(ans)fl

    return 0;
}
