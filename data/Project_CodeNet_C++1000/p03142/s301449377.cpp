#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> ab(n + 1);
    vector<int> f(n + 1);
    rep(i, 0, n + m - 1) {
        int a, b;
        cin >> a >> b;
        ab[a].push_back(b);
        f[b]++;
    }
    vector<int> dag;
    vector<int> par(n + 1);
    set<int> st;
    rep(i, 1, n + 1) if (f[i] == 0) st.insert(i);
    while (!st.empty()) {
        int a = *st.begin();
        st.erase(a);
        f[a]--;
        dag.push_back(a);
        for (auto b : ab[a]) {
            f[b]--;
            if (f[b] == 0) {
                par[b] = a;
                st.insert(b);
            }
        }
    }
    rep(i, 1, n + 1) cout << par[i] << endl;

    return 0;
}
