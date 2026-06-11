// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using P = pair<int, int>;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define a first
#define b second
const int MAX = 10101;
int d[MAX];   // 頂点 1 からの 距離 を 保存.
int c[MAX];   // 与えられた正の整数.
int ans[MAX]; // 書き込み方.

// グラフを幅優先探索する.
// https://ja.wikipedia.org/wiki/幅優先探索
// ※bfsの動作確認用.
// @param G: グラフ.
// @param s: グラフの探索開始頂点.
// @param d: 探索開始地点からの距離.
// @return: 特に無し.
void bfs(vvi &G, int s, int* d){
    // 1. 空のキュー.
    queue<int> q;
    
    // 2. 訪問済みフラグ設定.
    d[s] = 0;    // スタート地点は, 距離ゼロを指定.
    
    // 3. 探索地点 s をキュー q に追加.
    q.push(s);
    while(!q.empty()){
        // 4. キューから取り出す.
        int u = q.front();
        q.pop();
        
        // 5. 取り出した要素を処理.
        for(auto &e : G[u]){
            // 6. 訪問済であれば, 処理をスキップ.
            if(d[e] > 0)            continue;
            if(d[e] == 0 && e != s) d[e] = d[u] + 1, q.push(e);
        }
    }
    return;
}

int main(){
    
    // 1. 入力情報.
    int N, a, b, sum = 0;
    scanf("%d", &N);
    vvi G(N);
    rep(i, N - 1){
        scanf("%d %d", &a, &b);
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    rep(i, N){
        scanf("%d", &c[i]);
        sum += c[i];
    }
    
    // 2. 降順sort.
    sort(c, c + N, greater<int>());
    // rep(i, N) printf("%d ", c[i]);
    // puts("");
    
    // 3. 頂点 1 から 各頂点までの距離を計算.
    bfs(G, 0, d);
    // rep(i, N) printf("%d ", d[i]);
    // puts("");
    
    // 4. 頂点 と 距離 の ペア を 保存.
    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i, N) pq.push({d[i], i}); // {距離, 頂点番号}
    
    // 5. スコアの最大値, 書き込み方は？
    int idx = -1;
    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        ans[p.b] = c[++idx];
    }
    
    // 6. 出力.
    printf("%d\n", sum - c[0]);
    rep(i, N){
        printf("%d", ans[i]);
        if(i < N - 1) printf(" ");
    }
    return 0;
    
}