#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//UF Tree

struct UnionFind{

    //親番号の配列。自身が親なら木の頂点数*(-1)

    vector<int> r;

    //最初はバラバラなので全部親として初期化

    UnionFind(int N){
        r = vector<int>(N, -1);
    }

    //xの親を根にする関数

    int root(int x){
        if(r[x] < 0)return x;
        return r[x] = root(r[x]);
    }

    //二つの子を同じ根に結び付ける関数

    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(r[x] > r[y])swap(x,y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    //木の枝の数

    int size(int x){
        return -r[root(x)];
    }

    //同グループかの判定

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> p(N);

    for(int i = 0; i < N; i++){
        cin >> p[i];
        p[i] -- ;
    }

    UnionFind UF(N); //集合の生成,インスタンス化
    for(int i = 0; i < M; i++){
        int A,B;
        cin >> A >> B;
        A--; B--;

        UF.unite(A,B);
    }

    //i番目の要素がiのあるグループにあればよい
    int ans = 0;

    for(int i = 0; i < N; i++){
        if(UF.same(p[i],i))ans++;
    }

    cout << ans << endl;



}