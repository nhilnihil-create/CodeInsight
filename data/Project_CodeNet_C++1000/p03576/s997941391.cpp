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
const ll INF=1LL<<62;
const ll MOD=1000000007;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> x(N,0);
    vector<ll> y(N,0);
    ll ans=INF;
    for(ll i=0;i<N;++i)cin>>x[i]>>y[i];
    for(ll i=0;i<N;++i){
        for(ll j=i+1;j<N;++j){
            vector<ll> Y(0);
            //x[i]とx[j]を選んだ;
            ll x1=min(x[i],x[j]);
            ll x2=max(x[i],x[j]);
            for(ll k=0;k<N;++k){
                if(x1<=x[k]&&x[k]<=x2)Y.emplace_back(y[k]);
            }
            sort(Y.begin(), Y.end());
            if(Y.size()<K)continue;
            ll H=INF;
            for(ll i=0;i<Y.size()-K+1;++i)chmin(H,Y[i+K-1]-Y[i]);
            chmin(ans,(x2-x1)*H);
        }
    }
    prt(ans)
    
    return 0;
}
