#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
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
const ll MOD=1000000007;

template <typename T>
T manhattan(T x1,T y1,T x2,T y2){
    ll a=x1-x2,b=y1-y2;
    return max(a,-a)+max(b,-b);
}


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll H;
    cin >> H;
    ll W;
    cin >> W;
    ll D;
    cin >> D;
    vector<vector<ll>> A(H, vector<ll>(W, 0));
    for(ll i=0;i<H;++i)
        for(ll j=0;j<W;++j)cin>>A[i][j];
    vector<ll> wherex(H*W+1,0);
    vector<ll> wherey(H*W+1,0);
    for(ll i=0;i<H;++i)
        for(ll j=0;j<W;++j){
            wherex[A[i][j]]=i;
            wherey[A[i][j]]=j;
        }
    ll Q;
    cin >> Q;
    vector<ll> L(Q,0);
    vector<ll> R(Q,0);
    for(ll i=0;i<Q;++i)cin>>L[i]>>R[i];
    vector<ll> d(H*W+1,INF);
    for(ll i=1;i<=D;++i){
        ll k=i;ll l=0;
        while(1){
            d[k]=l;
            k+=D;
            if(k>H*W)break;
            l+=manhattan(wherex[k-D],wherey[k-D],wherex[k],wherey[k]);
        }
    }
    for(ll i=0;i<Q;++i){
        prt(d[R[i]]-d[L[i]])
    }


    return 0;
}
