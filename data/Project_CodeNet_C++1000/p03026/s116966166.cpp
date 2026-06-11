#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可
//乗算の際にオーバーフローに注意せよ！！（適切にmodをとれ）
//制約をよく読め！

const ll INF=1e18;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    V<ll> ans(N);
    V<int> deg(N);
    priority_queue<ll> pq;
    ll cnt=0;
    M=N-1;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    rep(i,N){
        ll c;
        cin>>c;
        pq.push(c);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    int s;//sは出発点、tは目的地 入力等をちゃんと行え
    rep(i,N){
        if(deg[i]==1){
            s=i;
            break;
        }
    }

    // 初期条件 (頂点 s を初期ノードとする)
    dist[s] = 0;
    que.push(s); // s を橙色頂点にする
    ans[s]=pq.top();
    pq.pop();
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない
            
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            ll cc=pq.top();
            ans[nv]=cc;
            cnt+=cc;
            pq.pop();
            que.push(nv);
        }
    }
    cout<<cnt<<'\n';
    rep(i,N) cout<<ans[i]<<' ';
}