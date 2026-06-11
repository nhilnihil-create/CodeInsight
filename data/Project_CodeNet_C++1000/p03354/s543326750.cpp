#include <bits/stdc++.h>
using namespace std;

static const int MAX = 100000;
vector<int> par(MAX);
vector<int> r(MAX);

void init(int n) {
    for (int i=0;i<n;i++) {
        par[i] = i;
        r[i] = 0;
    }
}

int root(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = root(par[x]);
    }
}

bool same(int x, int y) {
    return root(x) == root(y);
}

void unite(int x,int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    
    if (r[x] < r[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (r[x] == r[y]) r[x]++;
    }
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> P(N+1);
    for (int i=1;i<N+1;i++) cin >> P[i];
    int a,b;
    init(N+1);
    for (int i=0;i<M;i++) {
        cin >> a >> b;
        unite(a,b);
    }
    int cnt = 0;
    for (int i=1;i<N+1;i++) {
        if (same(i,P[i])) cnt++;
    }
    cout << cnt << endl;
}