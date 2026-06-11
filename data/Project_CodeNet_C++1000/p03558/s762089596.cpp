//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

int main(){
    ll K;
    cin>>K;
    vector<vector<pair<ll,ll>>> G(K+1);

    REP(i,K+1){
        G[i].push_back(make_pair(1,(i+1)%K));
        if(i>=1) G[i].push_back(make_pair(0,(i*10)%K));
    }

    //ダイクストラ O(ElogV)
    // データ構造
    vector<ll> dist(K, INF); // 全頂点を「未訪問」に初期化
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
    
    // 初期条件 (頂点 1を初期ノードとする)
    dist[1] = 0;
    que.push(make_pair(0,1));//1をスタート位置
    
     // 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        pair<ll,ll> p = que.top();
        que.pop();
        ll d=p.first;
        ll v=p.second;
        if(dist[v]<d) continue;
        for (auto nv : G[v]) {
            ll nd=d+nv.first;
    
            // 新たな頂点 nv について距離が短いなら更新
            if(nd<dist[nv.second]){
                dist[nv.second] = nd;
                que.push(make_pair(nd,nv.second));
            }
        }
    }
    cout<<dist[0]+1<<endl;

}