#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

struct UnionFind {
    vector<pair<long long, long long>> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(long long N) : par(N) { //最初は全てが根であるとして初期化
        for(long long i = 0; i < N; i++) {
          par[i].first = i;
          par[i].second = 1;
        }
    }

    long long root(long long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x].first == x) return x;
        return par[x].first = root(par[x].first);
    }

    void unite(long long x, long long y) { // xとyの木を併合
        long long rx = root(x); //xの根をrx
        long long ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[ry].second += par[rx].second;
        par[rx].first = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(long long x, long long y) { // 2つのデータx, yが属する木が同じならtrueを返す
        long long rx = root(x);
        long long ry = root(y);
        return rx == ry;
    }
};

long long N, M;
pair<long long, long long> p[100000];

int main() {
  cin >> N >> M;
  for(long long i = 0; i < M; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].first--;p[i].second--;
  }

  UnionFind tree(N);

  long long ans[100001] = {0};
  ans[0] = N * (N-1) / 2;

  for(long long i = M - 1; i >= 1; i--) {
    long long s = p[i].first, t = p[i].second;
    if(!tree.same(s, t)) {
      long long rs, rt;
      rs = tree.root(s);
      rt = tree.root(t);
      long long n = tree.par[rs].second * tree.par[rt].second;
      // cout << s << " " << t << endl;
      // cout << rs << " " << rt << " " << n << endl;
      ans[M-i] = ans[M-i-1] - n;
    } else {
      ans[M-i] = ans[M-i-1];
    }
    tree.unite(s, t);
  }

  for(long long i = M-1; i >= 0; i--) {
    cout << ans[i] << endl;
  }

  return 0;
}