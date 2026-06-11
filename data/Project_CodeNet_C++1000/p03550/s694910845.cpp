// https://atcoder.jp/contests/abc078/tasks/arc085_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> v(n);
    REP(i, n) cin >> v[i];
    if (n == 1) {
        cout << abs(v[0] - w) << endl;
    } else {
        int t1 = abs(v[n - 1] - w);
        int t2 = abs(v[n - 1] - v[n - 2]);
        cout << max(t1, t2) << endl;
    }
    return 0;
}