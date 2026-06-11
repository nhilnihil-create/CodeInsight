#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = -INF;

    int ans = INF;
    for (int i = 0; i < n; i++) {
        // a[i] から取る
        vector<int> b(n + 1), cand;
        for (int j = 0; j <= n; j++) {
            b[j] = a[j];
        }
        int left = -1, right = -1;
        for (int j = 0; j <= n; j++) {
            if (b[j] >= a[i]) {// a[i] 以上だけの区間を探す
                if (left == -1) {
                    left = j;
                    right = j + 1;
                } else {
                    right = j + 1;
                }
            } else {
                if (right - left >= k) {// [left, right) の中で小さい方から right - left - k + 1 個を取り除く候補に追加
                    sort(b.begin() + left, b.begin() + right);
                    for (int l = 0; l < right - left - k + 1; l++) {
                        cand.push_back(b[left + l]);
                    }
                }
                left = -1;
                right = -1;
            }
        }
        sort(cand.begin(), cand.end());
        if (cand.size() >= q) {
            ans = min(ans, cand[q - 1] - cand[0]);
        }
    }

    cout << ans << endl;
    return 0;
}