#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

vector<bool> visited(105);
vector<vector<int>> edge(105);
bool dfs(int cur, int par) {
    // if a cycle doesn't exist, return true
    visited[cur] = true;
    bool ic = false;
    if (edge[cur].size() == 0) {
        return true;
    } else {
        for (int i = 0; i < edge[cur].size(); i++) {
            if (edge[cur][i] == par) {
                continue;
            }
            if (visited[edge[cur][i]]) {
                ic = true;
                break;
            } else {
                visited[edge[cur][i]] = true;
            }
            if (!dfs(edge[cur][i], cur)) {
                ic = true;
            }
        }
        if (ic) {
            return false;
        } else {
            return true;
        }
    }
}
signed main() {
    long long n, ans = 0;
    cin >> n;
    vector<long long> as(n);
    map<long long, long long> cnt;
    REP(i, n) { cin >> as[i]; }
    vector<long long> kakakakakakakakakaak(n);
    kakakakakakakakakaak[0] = as[0];
    cnt[kakakakakakakakakaak[0]]++;
    if (kakakakakakakakakaak[0] == 0){
        ans++;
    }
    cnt[0]++;
    for (long long i = 1; i < n; i++) {
        kakakakakakakakakaak[i] = kakakakakakakakakaak[i - 1] + as[i];
        cnt[kakakakakakakakakaak[i]]++;
        if (cnt[kakakakakakakakakaak[i]] > 1) {
            ans += cnt[kakakakakakakakakaak[i]] - 1;
        }
    }
    cout << ans << endl;
}