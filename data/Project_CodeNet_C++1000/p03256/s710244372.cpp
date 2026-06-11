#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<set<int>> g(n);
    vector<int> a(n), b(n);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    set<int> st;
    rep(i, 0, n) {
        for (int to : g[i]) {
            if (s[to] == 'A')
                a[i]++;
            else
                b[i]++;
        }
        if (a[i] * b[i] == 0) st.insert(i);
    }
    int sz = n;
    while (st.size()) {
        int v = *st.begin();
        st.erase(st.begin());
        sz--;
        for (int to : g[v]) {
            if (to == v) continue;
            g[to].erase(v);
            if (s[v] == 'A')
                a[to]--;
            else
                b[to]--;
            if (a[to] * b[to] == 0) st.insert(to);
        }
    }
    cout << (sz ? "Yes" : "No") << endl;
    return 0;
}