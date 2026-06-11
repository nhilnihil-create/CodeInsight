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

int gcd(int a, int b) { // aとbの最大公約数（ユークリッドの互除法）
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd(vector<int> &a) { //  配列a[i]の最大公約数
    int r;
    rep(i, (int)a.size()) {
        if (i == 0) r = a[i];
        r = gcd(r, a[i]);
    }
    return r;
}

int main() {
    // input
    int n, x;
    cin >> n >> x;
    vi a(n);
    vi b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = abs(x-a[i]);
    }
    // solve
    // int prev = abs(x-a[0]);
    // rep(i, n) { // |x-a[i]|のgcdを求める
    //     if (i == 0) continue;
    //     prev = gcd(prev, abs(x-a[i]));
    // }
    int ans = gcd(b);
    // output
    cout << ans << "\n";
}