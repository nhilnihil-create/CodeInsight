#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2005, inf = 1e18;
int n, K, q, a[N], ans = inf;
bool unUse[N];

int solve (int pos) {
    int ret = 0, cnt = 0;
    priority_queue<int, vector<int>, greater<int> > pq, choo;

    unUse[n + 1] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        if (unUse[i]) {
            while (pq.size() >= K) choo.push(pq.top() ), pq.pop();
            while (!pq.empty() ) pq.pop();
        }
        else pq.push(a[i]);
    }

    if (choo.size() < q) return 2 * inf;

    while (cnt < q) ret = max(ret, choo.top() ), choo.pop(), cnt ++;

    cnt = 1;
    for (int i = pos + 1; i <= n; ++i) {
        if (unUse[i]) break;
        cnt ++;
    }
    for (int i = pos - 1; i > 0; --i) {
        if (unUse[i]) break;
        cnt ++;
    }
    if (cnt < K) return inf;
    return ret;
}

signed main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> K >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        memset(unUse, 0, sizeof unUse);
        for (int j = 1; j <= n; ++j) if (a[j] < a[i]) unUse[j] = 1;
        ans = min(ans, solve(i) - a[i]);
    }

    cout << ans;

    return 0;
}
