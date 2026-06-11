#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    int n, k;
    cin >> n >> k;
    int v[n];
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = 0;
    for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k - x; y++) {
            int z = k - (x + y);
            priority_queue<int, vector<int>, greater<int>> que;
            int sum = 0;
            for (int i = 0; i < min(x, n); i++) {
                sum += v[i];
                que.push(v[i]);
            }
            for (int i = n - 1; i >= max(0, n - y) && que.size() < n; i--) {
                sum += v[i];
                que.push(v[i]);
            }
            for (int i = 0; i < z && !que.empty(); i++) {
                int t = que.top(); que.pop();
                if (t >= 0) break;
                sum -= t;
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
}