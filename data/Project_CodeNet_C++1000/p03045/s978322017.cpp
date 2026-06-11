#include <bits/stdc++.h>

using namespace std;


class UF{
  private:
    int n;
    vector<int> r, p;
  public:
    UF(int num){
      n = num;
      for(int i=0;i<n;i++){
        r.push_back(1);
        p.push_back(i);
      }
    }
    int find(int x){
      if(x == p[x])return x;
      return p[x] = find(p[x]);
    }
    bool same(int x, int y){
      return find(x) == find(y);
    }
    void unite(int x, int y){
      x = find(x), y = find(y);
      if(x==y)return;
      if(r[x]<r[y])swap(x, y);
      r[x] += r[y];
      p[y] = x;
      n--;
    }
    int size(int x){
      return r[find(x)];
    }
    int cnt(){
      return n;
    }
};

int main(){
  int n, m;
  cin >> n >> m;
  UF uf=UF(n);
  for(int i=0;i<m;i++){
    int x, y, z;
    cin >> x >> y >> z;
    x--;y--;
    uf.unite(x, y);
  }
  cout << uf.cnt() << endl;
}

