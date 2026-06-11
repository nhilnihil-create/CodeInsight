#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    queue<vector<int>> que;
    que.push(l);
    int ans = 1 << 16;
    while (!que.empty()) {
        vector<int> front = que.front();
        que.pop();
        int sz = front.size();
        sort(front.begin(), front.end());
        if (sz == 3) {
            int score = abs(front[0] - c) + abs(front[1] - b) + abs(front[2] - a) + 10 * (n - sz);
            ans = min(ans, score);
        } else {
            int sm = 1 << 16;
            for (int i = 0; i < sz - 2; i++) {
                for (int k = i + 1; k < sz - 1; k++) {
                    for (int l = k + 1; l < sz; l++) {
                        int cur = abs(front[i] - c) + abs(front[k] - b) + abs(front[l] - a);
                        sm = min(sm, cur);
                    }
                }
            }
            ans = min(ans, 10 * (n - sz) + sm);
            for (int i = 0; i < sz - 1; i++) {
                for (int k = i + 1; k < sz; k++) {
                    vector<int> nw = front;
                    nw[i] = front[i] + front[k];
                    nw.erase(nw.begin() + k);
                    que.push(nw);
                }
            }
        }
    }
    cout << ans;
    return 0;
}