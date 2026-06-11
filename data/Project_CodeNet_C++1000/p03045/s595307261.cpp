#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct UnionFind{//雛形を与える(初期化と結合のみ)
    vector<int> par;//親(根)
    vector<int> rank;//木の深さ

    void init(int n){//初期化関数
        par.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;//初めはノード一個の木なので根は自身
            rank[i] = 1;
        }
    }

    int root(int x){//木の根を求める
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
    }

    bool same(int x, int y){//同じ木かどうか判定
        return root(x) == root(y);//同じ木ならtrue
    }

    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;//もし同じ木に属していたら何もしない
        if(rank[x] < rank[y]) swap(x, y);//数が大きい方に小さい方を結合させる
        par[y] = x;
        rank[x] += rank[y];//深さが同じ時だけ結合後深さが増える
    }

    int size(int x) {//深さを返す関数
        return rank[root(x)];
    }
};
int main(){
    int N, M;
    cin >> N >> M;
    UnionFind U;
    vector<long long> X(M), Y(M), Z(M);
    vector<long long> cnt(M, 0);
    U.init(N);
    for(int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--;
        Y[i]--;
        U.unite(X[i], Y[i]);
    }
    set<long long> s;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(!s.count(U.root(i))){
            ans++;
            s.insert(U.root(i));
        }
    }
    cout << ans << endl;
}