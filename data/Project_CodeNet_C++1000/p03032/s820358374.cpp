#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using gp = priority_queue<int, vector<int>, greater<int>>;
int N, K;
vector<int> D;

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int v; cin >> v;
        D.push_back(v);
    }
    int limit = min(N, K);
    ll ans = 0;
    for (int i = 0; i <= limit; ++i) {
        for (int j = 0; j + i <= limit; ++j) {
            ll now = 0;
            gp copy;
            for (int k = 0; k < i; ++k) {
                now += D[k];
                copy.push(D[k]);
            }
            for (int k = 1; k <= j; ++k) {
                int x = D[N - k];
                now += x;
                copy.push(x);
            }
            int d = K - i - j;
            for (int k = 0; k < d; ++k) {
                if (copy.empty()) break;
                int v = copy.top();
                if (v >= 0) break;
                copy.pop();
                now -= v;
            }
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}

