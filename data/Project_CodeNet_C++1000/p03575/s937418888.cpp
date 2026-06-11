#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

/*
  UnionFind Tree
*/
class UnionFind {
    private: 
        vector<int> par;
        vector<int> rank;
        vector<int> cnt;
    
    public:
        UnionFind(int n);
        int find(int x);
        void unite(int x, int y);
        bool same(int x, int y);
        int count(int x);
        void printStatus();
};

UnionFind::UnionFind(int n) {
    for (int i = 0; i < n; i++) {
        par.push_back(i);
        rank.push_back(0);
        cnt.push_back(1);
    }
}
int UnionFind::find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}
void UnionFind::unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
        cnt[y] += cnt[x];
        par[x] = y;
    } else {
        cnt[x] += cnt[y];
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}
bool UnionFind::same(int x, int y) {
    return find(x) == find(y);
}
int UnionFind::count(int x) {
    return cnt[find(x)];
}
void UnionFind::printStatus() {
    printf("----------------\n");
    for (int i = 0; i < par.size(); i++) {
        printf("[node %d]: parent = %d, rank = %d, count = %d\n", i, par[i], rank[i], cnt[i]);
    }
}

int main() {
  
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  rep(i,M) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  int ans = 0;

  rep(i,M) {
    UnionFind tree(N);
    rep(j,M) {
      if (i != j) tree.unite(a[j], b[j]);
    }
    bool flag = true;
    rep(j,N) {
      if (!tree.same(0,j)) flag = false;
    }
    if (!flag) ans++;
  }

  cout << ans << endl;

  return 0;
}