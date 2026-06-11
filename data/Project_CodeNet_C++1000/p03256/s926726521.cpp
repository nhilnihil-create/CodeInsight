#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

typedef long long ll;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 3 + 10, INF = 1e9 * 1000;
vector<vector<ll>> gr;
string s;
bool used[SIZE], good[SIZE];

void dfs(int v) {
    used[v] = 1;

    for (auto to : gr[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

int main() {
    fastInp;
    
    ll n, m;
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n; i++) good[i] = 1;

    gr.resize(n);
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    cerr << "baka\n";
    vector<ll> bd, cnt[2];
    cnt[0].resize(n);
    cnt[1].resize(n);
    for (int i = 0; i < n; i++) {
        ll fl1 = 0, fl2 = 0;
        for (auto to : gr[i]) {
            if (s[to] == 'A') {
                fl1++;
            } else {
                fl2++;
            }
        }
        if (!((fl1 >= 1) && (fl2 >= 1))) {
            bd.push_back(i);
            good[i] = 0;
        }
        cnt[0][i] = fl1;
        cnt[1][i] = fl2;
    }

    while (!bd.empty()) {
        ll v = bd.back();
        bd.pop_back();

        ll cur = !(s[v] == 'A');
        for (auto to : gr[v]) {
            bool k = 0;
            if ((cnt[1][to] >= 1 && cnt[0][to] >= 1)) k = 1;
            cnt[cur][to]--;
            if ((cnt[1][to] >= 1 && cnt[0][to] >= 1)) k = 0;

            if (k) {
                bd.push_back(to);
                good[to] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (good[i]) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}
