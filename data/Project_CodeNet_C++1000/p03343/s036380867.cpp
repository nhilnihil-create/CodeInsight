#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll,ll>;
using um = unordered_map<ll,ll>;
#define fl cout<<flush;
#define endl '\n'
template <typename T> inline void prt(T v){cout<<v<<'\n';}
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=(ll)1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    ll Q;
    cin >> Q;
    vector<ll> A(N,0);
    for(ll i=0;i<N;++i)cin>>A[i];
    ll ans=INF;
    //最小がA[i]の時
    for(ll i=0;i<N;++i){
        vector<vector<ll>> vec(0, vector<ll>(0));
        vector<ll> list(0);
        list.emplace_back(-1);
        for(ll j=0;j<N;++j){
            if(A[j]<A[i])list.emplace_back(j);
        }
        list.emplace_back(N);
        for(ll j=0;j<list.size()-1;++j){
            if(list[j+1]-list[j]==1)continue;
            vl G={};
            for(ll k=list[j]+1;k<=list[j+1]-1;++k)G.emplace_back(A[k]);
            vec.emplace_back(G);
        }
        vl F={};
        for(ll j=0;j<vec.size();++j){
            sort(vec[j].rbegin(), vec[j].rend());
            for(ll k=K-1;k<vec[j].size();++k){
                F.emplace_back(vec[j][k]);
            }
        }
        sort(F.begin(), F.end());
        if(F.size()<Q)continue;
        chmin(ans,F[Q-1]-F[0]);
    }

    prt(ans);

    return 0;
}

