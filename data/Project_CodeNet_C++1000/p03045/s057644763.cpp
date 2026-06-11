#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct UnionFind {
    vector<int> par;// par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  
    UnionFind(int N): par(N) {
        for (int i = 0; i < N; i++) par[i] = i; // 初期では親は自分自身
    }
  
    void init(int N) {
        par.resize(N);
        for (int i = 0; i < N; i++) par[i] = i; // 初期では親は自分自身
    }
  
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
        //return par[x];
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
  
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならfalseを返す
        int rx = root(x);
        int ry = root(y);
        return rx != ry;
    }
};

int main() {
    float N, M;
    cin >> N >> M;
  
    vector<vector<float>> data(M, vector<float>(3));//input　　
    float ans;
    ans = 1;
  
    for(int i = 0; i < M; i++) {
        float x, y, z;
        cin >> x >> y >> z;
        data[i][0] = x;
        data[i][1] = y;
        data[i][2] = z;
    }
  
    UnionFind tree(N + 1);
      
    for (int i = 0; i < M; i++) {
      //tree.init(N + 1);//毎回ツリーを初期化
      //cout << i << endl;
      tree.unite(data.at(i).at(0), data.at(i).at(1));
    }
    
    for (int i = 2; i <= N; i++) {
      //tree.init(N + 1);//毎回ツリーを初期化
      //cout << i << endl;
      if (tree.same(1, i)) {
        ans += 1;
        tree.unite(1, i);  
      }
      //cout << ans << endl;
    }
    cout << ans << endl;
  
    return 0;
}
