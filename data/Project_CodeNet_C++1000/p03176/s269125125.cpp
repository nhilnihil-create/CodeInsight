#include<bits/stdc++.h>
using namespace std;
const int N = (1 << 18);
int h[200010], a[200010], ch[200010];
map<int, long long> dp;
map<int, int> ind;
long long segt[N * 2];
void update(int idx, long long val) {
    idx += N - 1;
    segt[idx] = val;
    for (idx /= 2; idx >= 1; idx /= 2) {
        segt[idx] = max(segt[idx * 2], segt[idx * 2 + 1]);
    }
}
long long query(int r) {
    r += N - 1;
    int l = N;
    long long mx = 0;
    for (; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) {
            mx = max(mx, segt[l]);
            ++l;
        }
        if (r % 2 == 0) {
            mx = max(mx, segt[r]);
            --r;
        }
    }
    return mx;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        ch[i] = h[i];
    }
    sort(ch + 1, ch + 1 + n);
    for (int i = 1; i <= n; ++i) {
        ind[ch[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[h[i]] = a[i] + query(ind[h[i]] - 1);
        //cout << dp[h[i]] << '\n';
        update(ind[h[i]], dp[h[i]]);
    }
    long long answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer = max(answer, dp[h[i]]);
    }
    cout << answer;
}