#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

vector<int> toposort(vector<vector<int>> &g, vector<int> &h) {
    int n = g.size();
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(h[i] == 0) {
            st.push(i);
        }
    }
    vector<int> toposorted;
    while(st.size()) {
        int u = st.top();
        st.pop();
        toposorted.emplace_back(u);
        for(auto v : g[u]) {
            h[v]--;
            if(h[v] == 0) {
                st.push(v);
            }
        }
    }
    return toposorted;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n - 1 + m), b(n - 1 + m);
    vector<vector<int>> g(n);
    // 入次数
    vector<int> h(n, 0);
    for(int i = 0; i < n - 1 + m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        g[a[i]].emplace_back(b[i]);
        h[b[i]]++;
    }
    auto sorted = toposort(g, h);
    // 振り直した頂点番号
    vector<int> rev(n);
    for(int i = 0; i < n; i++) {
        rev[sorted[i]] = i;
    }

    vector<int> ans(n, sorted[0]);
    ans[sorted[0]] = -1;
    for(int i = 0; i < n - 1 + m; i++) {
        if(ans[b[i]] == -1) {
            continue;
        }
        if(rev[ans[b[i]]] < rev[a[i]]) {
            ans[b[i]] = a[i];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] + 1 << endl;
    }
}
