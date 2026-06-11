#include<bits/stdc++.h>
using namespace std;
int N, M, K;
vector<int> nakama;

class UnionFind {
public:
    vector <int> par; // 各元の親を表す配列
    vector <int> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(int sz_): par(sz_), siz(sz_, 1) {
        for (int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    
    void init(int sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);  // resize だとなぜか初期化されなかった
        for (int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    int root(int x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }
    
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y) { // 連結判定
        return root(x) == root(y);
    }

    int size(int x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

 

int main() {
    cin >> N >> M;
    vector<int> p(N);
    UnionFind Uni(N);
    int a, b;
    int ans=0;

    for(int i=0; i<N; i++){
	cin >> p[i];
	p[i]--;
    }



    for(int i=0; i<M; i++){
	cin >> a >> b;
	a--;
	b--;
	Uni.merge(a, b);
    }
    for(int i=0; i<N; i++){
	if(Uni.same(p[i], i))
	    ans++;
    }
    cout << ans << endl;

}

