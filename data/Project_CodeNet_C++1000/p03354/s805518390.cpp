#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
  vector<int> par; //par[i]はiの親の番号
  
  UnionFind(int N) : par(N)
  {
    for(int i = 0; i < N; i++) par[i] = i; //最初は全て根として初期化
  }
  
  int root(int x) //データxが属する木の根を再帰で得る root(x)={xの木の根}
  {
    if(par[x] == x) return x;
    return par[x] = root(par[x]); //親を再帰的にたぐり根を探す
  }
  
  void unite(int x, int y) //xとyの木を併合
  {
    int rx = root(x); //xの根
    int ry = root(y); //yの根
    if(rx == ry) return; //xとyの根が同じ(同じ木にある)ならそのまま
    par[rx] = ry; //xとyの根が同じでない(同じ木にない)ならyの根にxの根を付ける
  }
  
  bool same(int x, int y)//2つのデータx,yが同じ木に属するならtrue
  {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main()
{
  int N, M, x, y;
  cin >> N >> M;
  vector<int> p(N);
  
  int total = 0;
  UnionFind tree(N);
  
  for(int i = 0; i < N; i++){cin >> p.at(i);}
  for(int i = 0; i < M; i++)
  {
    cin >> x >> y;
    x--;
    y--;
    tree.unite(x, y);
  }
  for(int i = 0; i < N; i++)
  {
    if(tree.same(i, p.at(i) - 1)) total++;
  }
  cout << total << endl;
}