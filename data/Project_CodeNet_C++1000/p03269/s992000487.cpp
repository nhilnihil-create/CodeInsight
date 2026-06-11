#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 66;
int L;
int sum[N];
int n, m;
vector <pair<int, int> > g[N];
void add(int u, int v, int w, int op) {
    ++m;
    g[u].push_back(make_pair(v, w));
    if(op) sum[v] = sum[u] + w;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> L;
    int r;
    for(int i = 30; i >= 0; i--) if(L >> i & 1) {
        r = i; break;
    }
    for(int i = 2; i <= r + 1; i++) {
        add(i - 1, i, 1 << (i - 2), 1);
        add(i - 1, i, 0, 0);
    }
    int X = (1 << r); --L;
    while(X <= L) {
        int p = upper_bound(sum + 1, sum + r + 1, L - X) - sum - 1;
        add(p, r + 1, X, 0);
        X += sum[p] + 1;
    }
    n = r + 1;
    cout << n << ' ' << m << '\n';
    for(int u = 1; u <= n; u++) {
        for(auto it : g[u]) {
            int v = it.first, w = it.second;
            cout << u << ' ' << v << ' ' << w << '\n';
        }
    }
    return 0;
}
