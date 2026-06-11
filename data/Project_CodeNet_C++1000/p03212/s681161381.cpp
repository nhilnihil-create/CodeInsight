#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dfs(ll k, ll N) {
    if (k > N) return 0;
    ll tmp = k;
    vector<bool> ok(8, false);
    while (tmp != 0) {
        ok[tmp % 10] = true;
        tmp /= 10;
    }
    ll ret = 0;
    if (ok[3] && ok[5] && ok[7]) ++ret;
    ret += dfs(k * 10 + 3, N);
    ret += dfs(k * 10 + 5, N);
    ret += dfs(k * 10 + 7, N);
    return ret;
}

int main() {
    ll N; cin >> N;
    cout << dfs(0, N) << endl;
    return 0;
}
