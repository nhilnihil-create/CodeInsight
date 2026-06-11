//
// Created by Mahmoud Rashad on 11/27/19.
//

#include <bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<ii, ii>> vii;

const int MAXN = (int)1e5 + 5;



int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n;
    cin >> n;
    long long ans = 0;
    int mn = INT_MAX;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == b)
            ++cnt;
        ans += a;
        if (a > b) {
            mn = min(mn, b);
        }
    }

    if (cnt == n) {
        cout << 0 << '\n';
        return 0;
    }
    if (mn == INT_MAX)
        mn = 0;
    cout << ans - mn << '\n';

    return 0;
}