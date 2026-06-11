#pragma GCC optimize("O3")
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
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    vector<ll> B(N,0);
    for(ll i=0;i<N;++i)cin>>A[i]>>B[i];
    if(A==B){prt(0)return 0;}
    ll sum=0;
    for(ll i=0;i<N;++i)sum+=A[i];
    ll mark=INF;
    for(ll i=0;i<N;++i){
        if(A[i]>B[i])chmin(mark,B[i]);
    }
    prt(sum-mark)


    return 0;
}
