#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int p[100003];
int par[100003];

int root(int i) {
    if (par[i] == i)
        return i;
    return par[i] = root(par[i]);
}

void unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx != ry)
        par[rx] = ry;
}

int main() {
    int N, K;
    cin >> N >> K;
    rep2(i, N) {
        cin >> p[i];
        par[i] = i;
    }
    rep(i, K) {
        int a, b;
        cin >> a >> b;
        unite(p[a], p[b]);
    }
    int ans = 0;
    rep2(i, N) {
        if (root(i) == root(p[i]))
            ans++;
    }
    cout << ans << endl;
}