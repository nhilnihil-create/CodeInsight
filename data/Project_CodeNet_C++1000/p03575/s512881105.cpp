#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

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
main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> arr(M);
  rep(i, 0, M){
    int first, second;cin >> first >> second;
    arr[i].push_back(first);
    arr[i].push_back(second);
  }

  int ans = M;
  rep(i, 0, M){
    UnionFind uf(N + 1);
    rep(k, 0, M){
      if(i == k) continue;
      int a = arr[k][0];
      int b = arr[k][1];
      uf.merge(a, b);
    }

    rep(i, 1, N + 1){
      if(uf.size(i) == N){
        ans--;
        break;
      }
    }
    uf = NULL;
  }

  cout << ans << endl;

}


