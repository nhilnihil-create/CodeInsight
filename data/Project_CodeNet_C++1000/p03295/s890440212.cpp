#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

// secondの小さい順に並べる
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {

    int n, m; cin >> n >> m;

    vector<pair<int, int>> p(m);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        p[i] = make_pair(a, b);
    }

    sort(p.begin(), p.end(), cmp);

    int ans = 0;
    int end = 0;
    for (int i = 0; i < m; ++i) {
        if (p[i].first >= end) {
            end = p[i].second;
            ans++;
        }
    }

    cout << ans << endl;
}