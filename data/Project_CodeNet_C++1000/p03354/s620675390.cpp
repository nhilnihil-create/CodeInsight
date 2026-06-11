#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;

struct UnionFind {
    vector<int> par, rank, sz;
    
    UnionFind(int n) : par(n), rank(n, 0), sz(n, 1) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }
    void init(int n) {
        par.resize(n); rank.resize(n); sz.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, sz[i] = 1;
    }

    int root(int n)
    {
      if(par[n] == n) return n;
      else {
        return par[n] = root(par[n]);
      }
    }

    bool is_same(int a, int b)
    {
      return root(a) == root (b); 
    }

    int size(int n)
    {
      return sz[root(n)];
    }

    bool merge(int a, int b)
    {
      int rt_a = root(a);
      int rt_b = root(b);
      if(rt_a == rt_b) return false;
      if (rank[rt_a] < rank[rt_b]) swap(rt_a, rt_b);
      if (rank[rt_a] == rank[rt_b]) ++rank[rt_a];
      par[rt_b] = rt_a;
      sz[rt_a] += sz[rt_b];
      return true;
    }

};


int 
main()
{
  int N, M; cin >> N >> M;
  vector<int> arr(N);
  rep(i, 0, N){
    int tmp; cin >> tmp;
    --tmp;
    arr[i] = tmp;
  }
  UnionFind uf(N);
  rep(i, 0, M){
    int x, y; cin >> x >> y;
    --x, --y;
    uf.merge(x, y);
  }

  int ans = 0;
  rep(i, 0, N){
    if(uf.is_same(i, arr[i])) ++ans;
  }

  cout << ans << endl;

}
