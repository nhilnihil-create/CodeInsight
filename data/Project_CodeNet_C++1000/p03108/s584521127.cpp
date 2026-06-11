#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
  UnionFind tree;
  tree.init(N);
  vector<pair<int,int>> vp(M);
  rep(i,M){
    int x,y;
    cin>>x>>y;
    vp[i].first=x-1;
    vp[i].second=y-1;
  }
  vector<ll> ans(M+1,0LL);
  for(int i = M; i >=0; i--) {
    if(i==M) {
      ans[i]=(ll)N*(N-1)/2;
      continue;
    }
    if(tree.same(vp[i].first,vp[i].second)){
      ans[i]=ans[i+1];
      continue;
    }
    ans[i]=ans[i+1]-tree.size(vp[i].first)*tree.size(vp[i].second);
    tree.unite(vp[i].first,vp[i].second);
  }
  for(int i = 1; i < M+1; i++) {
    cout<<ans[i]<<endl;
  }
}
    