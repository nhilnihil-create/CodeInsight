#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
typedef pair<int, int> ii;

int n, k, q, a[2005], used[2005], ans = LLONG_MAX;

priority_queue<int, vector<int>, greater<int>> pq, pq1;

int lmao(int p) {
    used[n + 1] = 1;
    int cnt = 0, ret = 0;
    while(!pq.empty()) pq.pop();
    while(!pq1.empty()) pq1.pop();
    for(int i = p - 1; i >= 1; i--) {
        if(used[i]) break;
        cnt++;
    }
    for(int i = p; i <= n; i++) {
        if(used[i]) break;
        cnt++;
    }
    if(cnt < k) return LLONG_MAX;
    for(int i = 1; i <= n + 1; i++) {
        if(used[i]) {
            while(pq.size() >= k) {
                pq1.push(pq.top());
                pq.pop();
            }
            while(!pq.empty()) pq.pop();
        }
        else
            pq.push(a[i]);
    }
    cnt = pq1.size();
    if(cnt < q) return LLONG_MAX;
    cnt = q;
    while(cnt--) {
        ret = max(pq1.top(), ret);
        pq1.pop();
    }
    return ret;
}

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        memset(used, 0, sizeof(used));
        for(int j = 1; j <= n; j++) {
            if(a[j] < a[i])
                used[j] = 1;
        }
        int ret = lmao(i) - a[i];
        //cout << ret << "\n";
        ans = min(ans, ret);
    }
    cout << ans;
}
