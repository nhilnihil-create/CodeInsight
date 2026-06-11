#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    int a[m][2];
    
    rep(i, m){
        cin >> a[i][0] >> a[i][1];
      --a[i][0];--a[i][1];
    }
    
    int ans = 0;
    
    rep(i, m){
        
        UnionFind tree(n);
        rep(j, m){
        if(j != i)tree.unite(a[j][0], a[j][1]); // xの木とyの木を併合する
        }

         rep(k, n-1){
            if(tree.same(k, n-1) == false){
            ++ans;
            break;
            }
        }
    }
    
    cout<< ans << endl;

    return 0;
}