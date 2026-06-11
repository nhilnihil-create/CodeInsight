#include <bits/stdc++.h>
using namespace std;
using ipair = pair<int, int>;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1LL<<58;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};


int main(){
    int N, M;
    cin >> N >> M;

    vector<ipair> bridge(M);
    rep(i, M) cin >> bridge[i].first >> bridge[i].second;
    rep(i, M) {bridge[i].first--; bridge[i].second--;}

    UnionFind uf(N);

    vector<ll> ans(M);
    ans[M-1] = (ll)N*(N-1)/2;

    for(int i=M-1; i>=1; --i){
        int a = bridge[i].first;
        int b = bridge[i].second;

        ll tmp_ans = ans[i];

        if(uf.find(a) != uf.find(b)){
            tmp_ans -= uf.size(a) * uf.size(b);
            uf.unite(a, b);
        }
        ans[i-1] = tmp_ans;
    }

    rep(i, M) cout << ans[i] << endl;


    return 0;
}