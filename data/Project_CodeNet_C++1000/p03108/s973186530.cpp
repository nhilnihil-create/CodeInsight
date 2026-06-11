#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;

// UnionFind
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822
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

int main() {
    ll N,M;
    cin >> N >>M;
    vector<P> AB(M);
    for(int i=0;i<M;i++){
        ll A,B;
        cin >> A >>B;
        --A;--B;
        AB[i].first = A;
        AB[i].second = B;
    }
    ll addHappy[M] ={};
    UnionFind uf = UnionFind(N);
    for(int i=M-1;i>=0;--i){
        if(uf.same(AB[i].first,AB[i].second)){
            continue;
        }
        addHappy[i] = ll(uf.size(AB[i].first)) * ll(uf.size(AB[i].second));
        uf.unite(AB[i].first,AB[i].second);
    }
    ll temp =0;
    for(int i=0;i<M;i++){
        temp += addHappy[i];
        cout << temp << endl;
    }


    return 0;
}