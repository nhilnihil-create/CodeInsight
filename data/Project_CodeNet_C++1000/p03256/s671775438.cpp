#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int N = 2e5 + 7;
const int SQ = sqrt(N);

bitset <N> a[SQ];

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector <vector <int> > gr(n);
    vector <int> st(n, 0), c[2];
    c[0].resize(n, 0);
    c[1].resize(n, 0);
    vector <bool> exist(n, true);
    set <pair <int, int> > q;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
        st[v]++, st[u]++;
        c[s[v] - 'A'][u]++;
        c[s[u] - 'A'][v]++;
    }
    for (int i = 0; i < n; i++) {
        q.insert({st[i] - max(c[0][i], c[1][i]), i});
    }
    while (!q.empty()) {
        auto t = *q.begin();
        //cout << t.second << " " << t.first << "\n";
        if (t.first) break;
        int v = t.second;
        exist[v] = false;
        q.erase(q.begin());
        for (int u : gr[v]) {
            if (!exist[u]) continue;
            //cout << u << " ";
            q.erase({st[u] - max(c[0][u], c[1][u]), u});
            c[s[v] - 'A'][u]--;
            st[u]--;
            q.insert({st[u] - max(c[0][u], c[1][u]), u});
        }
        //cout << "\n";
    }
    if (q.size()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
