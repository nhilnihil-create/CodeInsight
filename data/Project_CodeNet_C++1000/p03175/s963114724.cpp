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
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld pi=3.141592653589793238;

//1-indexedなので注意！！！！
//＄１には頂点数＋３くらいをいれるといい
vector<vector<ll>> graph(100003, vector<ll>(0));  // DAG
vector<ll> order(0);  // トポロジカルソートされた頂点を格納
vector<bool> used(100003,0);  // 訪問済みフラグ

// 辿れるところまで辿る深さ優先探索
void dfs(ll u){
    if(used[u]) return;
    used[u] = true;
    for(ll v : graph[u]) dfs(v);
    order.emplace_back(u);     // 帰りがけ順で頂点を入れていく
}

// トポロジカルソート
//Nは頂点数
void tsort(ll N){
    for(ll v = 1; v <= N; v++) dfs(v);
    //reverse(order.begin(), order.end());
}
//1-indexedなので注意！！！！
//1-indexedなので注意！！！！
//1-indexedなので注意！！！！
//1-indexedなので注意！！！！

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> x(N-1,0);
    vector<ll> y(N-1,0);
    for(ll i=0;i<N-1;++i){
        cin>>x[i]>>y[i];
        graph[x[i]].emplace_back(y[i]);
        graph[y[i]].emplace_back(x[i]);
    }
    tsort(N);
    vector<bool> check(N+1,0);
    vector<ll> dpb(N+1,0);
    vector<ll> dpw(N+1,0);
    for(auto p: order){
        check[p]=1;
        ll retw=1;
        ll retb=1;
        for(auto q: graph[p]){
            if(!check[q])continue;
            retw*=dpw[q]+dpb[q];
            retb*=dpw[q];
            retw%=MOD;
            retb%=MOD;
        }
        dpw[p]=retw;
        dpb[p]=retb;
    }
    prt((dpw[order[N-1]]+dpb[order[N-1]])%MOD)


    return 0;
}
