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
#define endl '\n'
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
    ll T;
    cin >> T;
    ll A;
    cin >> A;
    vector<ll> H(N,0);
    for(ll i=0;i<N;++i)cin>>H[i];
    vector<pair<ld,ll>> P(N);
    for(ll i=0;i<N;++i)P[i]=make_pair(T-0.006*H[i],i);
    pair<ld,ll> ans=make_pair((ld)10000000,INF);
    function<ll()> solve=[&]{
        for(ll i=0;i<N;++i){
            if(abs(ans.first-A)>abs(A-P[i].first)){
                ans=P[i];
            }
        }
        
        return  ans.second+1;
    };
    prt(solve())

    return 0;
}
