#include<bits/stdc++.h>
using namespace std;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
int ans=0;

//Union-Find 素集合データ構造
struct UnionFind {

    vector<int> sz; // sz[i]:iが根のとき、木のサイズ それ以外の値に意味はない
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : sz(N),par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++){
            sz[i] = 1;
            par[i] = i;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int size(int x) { // データxが属する木の大きさを得る
        return sz[root(x)];
    }

    void unite(int x, int y) { //xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをryにつける
        sz[ry] += sz[rx];//yの大きさにxの大きさを足す
        //sz[rx]=-1;// 根でないデータの大きさに意味はない
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

};
void Main(){
    int n,m;cin>>n>>m;
    vector<int> p(n);
    For(i,0,n) {
        cin>>p[i];
        p[i]--;
    }
    UnionFind Tree(n);
    For(i,0,m){
        int x,y;cin>>x>>y;
        x--;y--;
        Tree.unite(x,y);
    }
    For(i,0,n) if(Tree.same(i,p[i])) ans++;
    cout<<ans<<endl; 
}
int main(){
    Main();
    return 0;
}
