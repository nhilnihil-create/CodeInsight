#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
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

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll C;
    cin >> C;
    vector<vector<ll>> D(C+1, vector<ll>(C+1, 0));
    for(ll i=0;i<C;++i)
        for(ll j=0;j<C;++j)cin>>D[i+1][j+1];
    vector<vector<ll>> c(N+1, vector<ll>(N+1, 0));
    for(ll i=0;i<N;++i)
        for(ll j=0;j<N;++j)cin>>c[i+1][j+1];

    //change[i][j]はあまりiのやつを色jに変えるために必要なコスト
    vector<vector<ll>> change(3, vector<ll>(C+1, 0));
    for(ll i=0;i<3;++i)
        for(ll j=1;j<=C;++j){
            for(ll k=1;k<=N;++k)
                for(ll l=1;l<=N;++l){
                    if((k+l)%3==i)change[i][j]+=D[c[k][l]][j];
                }
        }
    ll ans=INF;
    for(ll i=1;i<=C;++i){
        for(ll j=1;j<=C;++j){
            if(i==j)continue;
            for(ll k=1;k<=C;++k){
                if(i==k||j==k)continue;
                chmin(ans,change[0][i]+change[1][j]+change[2][k]);
            }
        }
    }
    prt(ans)

    return 0;
}
