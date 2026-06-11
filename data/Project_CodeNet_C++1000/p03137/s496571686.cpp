#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const ll INF = 1e18;
const int MAX = 1e6;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visited[MAX]; // 訪問状況


int main() {
    // input
    int n, m;
    cin >> n >> m;
    vi x(m);
    rep(i, m) {
        cin >> x[i];
    }
    // solve
    sort(ALL(x));
    vi y(m-1);
    rep(i, m-1) {
        y[i] = x[i+1] - x[i];
    }
    sort(ALL(y));
    // output
    if (n >= m) {
        cout << 0 << "\n";
    } else {
        int sum = 0;
        rep(i, m-n) {
            sum += y[i];
        }
        cout << sum << "\n";
    }
}