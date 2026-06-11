#include <bits/stdc++.h>
using namespace std;
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
struct position { long long x, y; };
const long long INF = INT64_MAX;

bool isin(long long l, long long r, long long d, long long u, position p) {
    return (l <= p.x && p.x <= r && d <= p.y && p.y <= u);
}

int main() {
    int n, k;
    cin >> n >> k;
    long long ans = INF;
    vector<position> data;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        data.push_back(position{x[i], y[i]});
    }
    
    sort(x.begin(), x.end()); sort(y.begin(), y.end());
    for (int l = 0; l < n; l++) for (int r = l; r < n; r++) {
        for (int d = 0; d < n; d++) for (int u = 0; u < n; u++) {
            int res = 0;
            for (auto& e : data) if (isin(x[l], x[r], y[d], y[u], e)) res++;
            if (k <= res) chmin(ans, abs(x[l] - x[r]) * abs(y[u] - y[d]));
        }
    }
    
    cout << ans << endl;
    return 0;
}