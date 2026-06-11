#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

ll par[100010];
ll size[100010];

int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}
ll find_size(int x) {
    return size[x] = size[find(x)];
}
bool same(int x, int y) {
    return find(x) == find(y);
}
void unit(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (!same(px, py)) {
        par[py] = px;
        size[px] += size[py];
        size[px] = size[px];
    } 
}

int main() {
    ll N, M;
    cin >> N >> M;
    
    ll A[M], B[M];
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, N+1) par[i] = i, size[i] = 1;

    ll ans[M+1];
    ans[M] = N * (N-1) / 2;

    for(int i=M-1; i>=0; i--) {
        if (same(A[i], B[i])) {
            ans[i] = ans[i+1];
        } else {
            ans[i] = ans[i+1] - find_size(A[i]) * find_size(B[i]);
            unit(A[i], B[i]);
        }
    }

    rep(i, M) cout << ans[i+1] << endl;

    return 0;
}

