#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

struct UnionFind {
    vector<int> par,rank,large;

    void init(int N){
        rank.assign(N,0);
        large.assign(N,1);
        par.resize(N);
        for(int i= 0; i < N; i++){
            par[i]=i;
        }
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if(rank[rx]<rank[ry]) {
            par[rx]=ry;
            large[ry]+=large[rx];
            large[rx]=0;
        }
        else {
            par[ry]=rx;
            large[rx]+=large[ry];
            large[ry]=0;
            if(rank[rx]==rank[ry])rank[x]++;
        }
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) {
        return large[root(x)];
    }
};

int main() {
  int N,M;
  cin>>N>>M;
  vector<vector<int>> v(M,vector<int>(3));
  for(int i = 0; i < M ;i++) cin>>v[i][0]>>v[i][1]>>v[i][2];
  UnionFind tree;
  tree.init(N);
  for(int i = 0; i < M; i++){
    tree.unite(v[i][0]-1,v[i][1]-1);
  }
  int ans = 0;
  for(auto x:tree.large){
    if(x!=0) ans++;
  }
  cout<<ans<<endl;
}