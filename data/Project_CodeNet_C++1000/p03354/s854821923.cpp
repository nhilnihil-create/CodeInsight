//unionfind
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct UnionFind{
    vector<int> d;//d[i]:iの親の番号。根なら木のサイズ*(-1)
    UnionFind(int n=0):d(n,-1){}//全ての木のサイズが１と初期.n点
    
    int find(int x){//根を返す
    if(d[x] < 0) return x;//xが根の時はxを返す
    return d[x] = find(d[x]);
    }

    bool unite(int x,int y){//xとyの木をつなげたらtrue.大きい方に小さい方をつなげる.
    x = find(x);y = find(y);//根を求める
    if(x==y) return false;//同じ木に属していたらつなげる必要なし
    if(d[x]>d[y]) swap(x,y);//yの方がサイズが大きい時は交換する
    d[x] += d[y];//サイズの更新
    d[y] = x;//根の更新
    return true;
    }

    bool same(int x,int y){return find(x)==find(y);}//xとyが同じ木にあるか

    int size(int x){return -d[find(x)];}//xの木のサイズを返す
};

int main(){
int n,q;
cin >> n >> q;
vector<int>p(n);
UnionFind tree(n);//////////////////定義の仕方
for (int i = 0; i <n; i++)
{
    cin>>p[i];
}

for(int i=0;i<q;i++){
    int x,y;cin>>x>>y;
    tree.unite(x-1,y-1);
}
int cnt=0;
for (int i = 0; i < n; i++)
{
    if(tree.same(p[i]-1,i)) {cnt++;}
}

cout << cnt << endl;
return 0;
}

