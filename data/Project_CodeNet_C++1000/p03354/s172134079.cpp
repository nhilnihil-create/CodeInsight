#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MAX_N = 1e+5 + 10;

int par[MAX_N]; // 親
int Rank[MAX_N]; // 木の深さ

// n要素で初期化
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        Rank[i] = 0;
    }
}
// 木の根を求める
int find(int x) {
    if (par[x] == x) {
    return x;
    } else {
    return par[x] = find(par[x]);
    }
}
// xとyの属する集合を併合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (Rank[x] < Rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
    if (Rank[x] == Rank[y]) Rank[x]++;
    }
}
// xとyが同じ集合に属するか否か
bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> p(N),x(M),y(M);
    REP(i,N) {
        int c;
        cin >> c;
        --c;
        p[i] = c;
    }
    REP(i,M) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        x[i] = a;
        y[i] = b;
    }
    
    init(N);
    REP(i,M){
        unite(p[x[i]],p[y[i]]);
    }
    
    int ans = 0;
    REP(i,N){
        if ( same(i,p[i]) ) ++ans;
    }
    
    cout << ans << endl;
    
    
    return 0;
}