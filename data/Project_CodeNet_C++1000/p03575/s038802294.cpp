#include <iostream>
#include <vector>

using namespace std;
#define ll long long

vector<int> par, rnk;
int g;
void init(int n) {
    g = n;
    par.clear();
    rnk.clear();
    par.resize(n);
    rnk.resize(n);
    for(int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}
int find(int x) {
    if(par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) {
        return;
    } else {
        if(rnk[x] < rnk[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if(rnk[x] == rnk[y]) rnk[x]++;
        }
    }
    g--;
}
bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    for(int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    int ans = 0;
    for(int i = 0; i < M; i++) {
        init(N);
        for(int j = 0; j < M; j++) {
            if(j == i) continue;
            unite(a[j], b[j]);
        }
        if(g == 2) ans++;
    }
    cout << ans << endl;
    return 0;
}