#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define nl '\n'
#define f(i, n) for (int i = 0; i < n; ++i)
#define INF 1e9 + 5
using namespace std;
void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int mx = -INF;
    f(i, n) {
        int c;
        cin >> c;
        if (c > mx) mx = c;
    }
    int mn = INF;
    bool war = false;
    f(i, m) {
        int c;
        cin >> c;
        if (c < mn) mn = c;
    }
    war = mn > mx && mn <= y && mn > x;
    cout << (war ? "No War" : "War") << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}