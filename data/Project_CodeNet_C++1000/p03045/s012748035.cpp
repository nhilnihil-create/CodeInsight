#include <bits/stdc++.h>
using namespace std;

class UnionFind {  
  public:
  vector<long long> par;
  vector<long long> rank;
 
  UnionFind(long long N) : par(N + 1), rank(N + 1){
    for(int i = 0; i < N; i++){  
      par[i] = i;
      rank[i] = 1;
    }
  }
 
  long long root(long long x){  
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
 
  long long size(long long x){  
    return rank[root(x)]; 
  }
 
  void unite(long long x, long long y){  
    long long rx = root(x); 
    long long ry = root(y);
    if (rx == ry) return;
 
    if(rank[rx] < rank[ry]){  
      par[rx] = ry; 
    } else{  
      par[ry] = rx;
      if(rank[rx] == rank[ry]) rank[rx]++; 
    }
  }
 
  bool same(long long x, long long y){  
    return root(x) == root(y); 
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, M;
  cin >> N >> M;
  UnionFind uf(N);
  for(int i = 0; i < M; i++){  
    int x, y, z;
    cin >> x >> y >> z; 
    x--; y--;
    uf.unite(x, y);
  }
  unordered_set<int> s;
  for(int i = 0; i < N; i++){  
    s.insert(uf.root(i));  
  }
  cout << s.size() <<endl;
}
