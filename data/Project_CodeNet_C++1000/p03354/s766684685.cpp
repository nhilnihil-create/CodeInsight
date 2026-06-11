#include<bits/stdc++.h>
using namespace std;

// なんとなく、置換できる組(xi,yi)をすべて集合にまとめて
// i番目の順列Piとインデックスiがおなじ集合に属しているなら
// 順列中のiとPiは置換できると考えた
// 合ってたけど、証明が書けるようになりたい。
// https://atc001.contest.atcoder.jp/tasks/unionfind_a
struct unionfind{
    vector<int> par, rank;
    unionfind(int s) {
        par.resize(s);
        rank.resize(s, 0);
        for(int i = 0; i < s; ++i) par[i] = i;
    }
    int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }
    bool same(int x, int y) { return root(x) == root(y); }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
};

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> P(N);
    unionfind List(N);
    for(int i = 0; i < N; ++i) {
        int p;
        scanf("%d", &p);
        P[i] = p-1;
    }
    for(int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        List.unite(x-1, y-1);
    }
    int res = 0;
    for(int i = 0; i < N; ++i) {
        if(List.same(i, P[i])) ++res;
    }
    printf("%d\n", res);
    return 0;
}