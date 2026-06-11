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

const int NMAX=200100;
using Graph=vector<vector<ll>>;

Graph G(NMAX);
vector<int> dist(NMAX, -1); // 全頂点を「未訪問」に初期化

int bfs(int s){
    queue<int> que;
    int res=s;
    // 初期条件 (頂点 0 を初期ノードとする)
    dist[s] = 0;
    que.push(s); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        res=v;

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    return res;
}



int main(){
    int N;
    cin>>N;
    
    REP(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int s1=bfs(0);
    dist.assign(NMAX,-1);
    int s2=bfs(s1);
    
    int d=dist[s2];
    if(d%3==1){
        cout<<"Second"<<endl;
    }else{
        cout<<"First"<<endl;
    }

    
    
}