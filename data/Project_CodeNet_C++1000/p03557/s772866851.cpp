#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 2e9;
// const ll INF = 1e12;
const int MAX = 1e6;
// const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visited[MAX]; // 訪問状況

int main() {
    // input
    int n;
    cin >> n;
    vi a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> b[i];
    }
    rep(i, n) {
        cin >> c[i];
    }
    // solve
    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));
    ll ans = 0;
    rep(j, n) {
        ll i = lower_bound(ALL(a), b[j]) - a.begin();
        ll k = c.end() - upper_bound(ALL(c), b[j]);
        ans += i * k;
    }
    // output
    cout << ans << endl;
}