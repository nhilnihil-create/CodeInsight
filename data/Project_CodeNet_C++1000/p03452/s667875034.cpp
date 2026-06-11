#include <bits/stdc++.h>
#define REP(i,n) for(int64_t i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REV(c) reverse((c).begin(),(c).end())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define COUTDOUBLE(d,i) cout << setprecision((i)) << (d) << endl;
#define VIN(v) for(int64_t i=0;i<(v).size();i++){cin >> (v).at(i);}
#define MREP(i,m) for(auto i=(m).begin(); i != (m).end(); ++i) // auto key = i->first;auto value = i->second;

using namespace std;
typedef int64_t I;
typedef pair<I,I> P;
typedef vector<I> V;

I MOD = pow(10,9)+7;
I MAX = LONG_MAX;
I MIN = LONG_MIN;

// 最大公約数
I gcd(I a, I b) {
  return b != 0 ? gcd(b, a % b) : a;
}

// 最小公倍数
I lcm(I a, I b) {
  return a * b / gcd(a, b);
}

int ctoi(char c){
  return c - '0';
}

template<class Abel> struct UnionFind {
    vector<I> par;
    vector<I> rank;
    vector<Abel> diff_weight;

    UnionFind(I n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(I n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (I i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    I root(I x) {
        if (par[x] == x) {
            return x;
        }
        else {
            I r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(I x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(I x, I y) {
        return root(x) == root(y);
    }

    bool merge(I x, I y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(I x, I y) {
        return weight(y) - weight(x);
    }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  I n,m;
  cin >> n >> m;
  UnionFind<int> uf(n+1);
  REP(i,m){
    I l,r,d;
    cin >> l >> r >> d;
    if (uf.issame(l,r)){
      if (uf.diff(l,r) == d){
      }else{
        No;
        return 0;
      }
    }else{
      uf.merge(l,r,d);
    }
  }
  Yes;
  return 0;
}

