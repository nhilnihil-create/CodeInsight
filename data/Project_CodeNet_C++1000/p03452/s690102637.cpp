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

vector<ll> vec(100005,INF);
vector<vector<P>> G(100005, vector<P>(0));

bool dfs(ll x, ll &Max, ll &Min){
    if(vec[x]==INF)vec[x]=0;
    bool ret=1;
    for(auto p: G[x]){
        //相手が探索済みで、矛盾が生じたとき
        if(vec[p.first]!=INF&&vec[p.first]-vec[x]!=p.second)ret=0;
        //未探索なら探索
        else if(vec[p.first]==INF){
            vec[p.first]=vec[x]+p.second;
            chmax(Max,vec[p.first]);
            chmin(Min,vec[p.first]);
            if(!dfs(p.first,Max,Min))ret=0;
        }
    }
    return ret;
}

int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> L(M,0);
    vector<ll> R(M,0);
    vector<ll> D(M,0);
    for(ll i=0;i<M;i++)cin>>L[i]>>R[i]>>D[i];
    for(ll i=0;i<M;i++){
        G[L[i]].emplace_back(P(R[i],D[i]));
        G[R[i]].emplace_back(P(L[i],-D[i]));
    }
    for(ll i=1;i<=N;i++){
        ll Min=0,Max=0;
        if(vec[i]==INF&&!dfs(i,Max,Min)){
            print("No")
            return 0;
        }
        if(Max-Min>1000000000){
            print("No")
            return 0;
        }
    }
    print("Yes")
    return 0;
}
