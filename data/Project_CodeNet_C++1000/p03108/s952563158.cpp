#include <bits/stdc++.h>
using namespace std;

////// Union Find https://atcoder.jp/contests/atc001/tasks/unionfind_a
// 引用資料：https://mickey24.hatenablog.com/entry/20090602/1243950241
// 経路圧縮のみ実装？ 深さ１の部分木を生成

class DisjointSet {
private:
    vector<int> p;              // 頂点 i の所属している集合の root を記録する or 集合の root には自分を含む要素数が負の数で記録してある
    int count;                  // 集合の数を記録(１となったときすべての要素が一つにまとまったことを示す)

    // 所属している集合の root を調べる
    int root(int x) {         
        return p[x] < 0 ? x : p[x] = root(p[x]);
    }

public:
    // コンストラクタ　要素数の提示が必要
    DisjointSet(int size) {
        p.resize(size, -1); 
        count = size;
    }
    // 集合同士の結合
    bool unite_set(int x, int y) {          
        int rootX = root(x);
        int rootY = root(y);

        if (rootX != rootY) {                       // 同集合内でのループが起こらないように
            if (p[rootX] > p[rootY]) {              // 自分を含む要素数が多い方を rootX とする  
                swap(rootX, rootY); 
            }
            p[rootX] += p[rootY];                   // 自分を含む要素数を p[rootX] に渡す
            p[rootY] = rootX;                       // root を変更
            count--;                                // 集合同士がつながったので、集合の数を一つ減らす
            return true;
        }
        return false;
    }
    // 集合の要素数を算出
    int number_of_elements(int x){
        int rootX = root(x);
        return abs(p[rootX]);
    }
    // 同じ集合に属しているか調べる
    bool is_same_set(int x, int y) {          
        if (root(x) == root(y)) {
            return true;
        }
        return false;
    }
    // 集合の数を出力
    int number_of_sets() {
        return count;
    }
};

int main() {
    // 入力
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edge;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;  b--;
        edge.push_back(make_pair(a, b));
    }

    DisjointSet islandSet(n);        // コンストラクト、インスタンス化
    // k頂点の往来の組み合わせを先に算出
    vector<long> combi(n+1);
    combi[1] = 0;
    for (int i = 2; i <= n; i++){
        combi[i] = combi[i-1] + i-1;
    }
    
    // 壊れるのが遅い橋から考える
    long inconvTmp = combi[n];
    vector<long> inconv;
    inconv.push_back(inconvTmp);
    for (int i = m-1; i >= 1; i--){
        // 
        pair<int, int> edgeTmp = edge[i];
        int bfr1Elements = islandSet.number_of_elements(edgeTmp.first);
        int bfr2Elements = islandSet.number_of_elements(edgeTmp.second);
        bool isUnite = islandSet.unite_set(edgeTmp.first, edgeTmp.second);
        if (isUnite){
            inconvTmp = inconvTmp - combi[bfr1Elements+bfr2Elements] + combi[bfr1Elements] + combi[bfr2Elements];
        }
        inconv.push_back( inconvTmp );
    }
    for (auto itr = inconv.end() - 1; itr != inconv.begin() - 1; itr--){
        cout << *itr << endl;
    }

    return 0;
}
