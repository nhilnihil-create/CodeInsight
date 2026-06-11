#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = 1 << 18 | 1;
const int inf = int(1e9);

pii f[N];
int n, k, a[N], g[N];

void maximize(pii& x, pii y) {
    vector<pii> v = {mp(a[x.fi], x.fi), mp(a[x.se], x.se), mp(a[y.fi], y.fi), mp(a[y.se], y.se)};
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    x.fi = v.back().se, x.se = v[v.size() - 2].se;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> k; n = 1 << k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i]; f[i].fi = i;
    }
    for(int i = 0; i < k; ++i) {
        for(int j = 1; j < n; ++j)
            if(j >> i & 1) maximize(f[j], f[j ^ (1 << i)]);
    }
    for(int i = 1; i < n; ++i) {
        g[i] = max(g[i - 1], a[f[i].fi] + a[f[i].se]);
        cout << g[i] << '\n';
    }
}
