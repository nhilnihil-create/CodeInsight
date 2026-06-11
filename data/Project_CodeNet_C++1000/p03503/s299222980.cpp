#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll costs [105][10];
ll p[100][11];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> costs[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 10; j++) {
            cin >> p[i][j];
        }
    }
    ll mx = -2e18;
    for (int i = 0; i < (1 << 10); i++) {
        bool can = false;
        int cnt[n];
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < n; k++) {
                    if (costs[k][j])
                        cnt[k]++;
                }
            }
        }
        ll currCost = 0;
        for (int j = 0; j < n; j++) {
            if (cnt[j])
                can = true;
            currCost += p[j][cnt[j]];
        }
        if (can)
            mx = max(mx, currCost);
    }
    cout << mx;
    return  0;
}