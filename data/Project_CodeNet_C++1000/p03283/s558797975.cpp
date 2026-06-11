#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N, M, Q;
    cin>>N>>M>>Q;
    vector<ll> L(M,0);
    vector<ll> R(M,0);
    for(ll i=0;i<M;i++)cin>>L[i]>>R[i];
    vector<ll> p(Q,0);
    vector<ll> q(Q,0);
    for(ll i=0;i<Q;i++)cin>>p[i]>>q[i];
    //vec[i]には、i以降からはじまる電車の区間の右端を格納
    vector<vector<ll>> vec(N+1, vector<ll>(0));
    for(ll i=0;i<M;i++)
        for(ll j=1;j<=L[i];j++)vec[j].emplace_back(R[i]);
    
    for(ll i=1;i<=N;i++)sort(vec[i].begin(), vec[i].end());
    for(ll i=0;i<Q;i++){
        print(upper_bound(vec[p[i]].begin(), vec[p[i]].end(), q[i])-vec[p[i]].begin())
    }

    return 0;
}