#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 5e5 + 2;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v.pb({y, x});
    }
    sort(v.rbegin(), v.rend());
    int ptr = 0;
    for (int i = 0; i < m; i++) {
        ll num = v[i].S, val = v[i].F;
        for (int i = 0; i < num; i++) {
            if (a[ptr] < val)
                a[ptr] = val, ptr++;
            else break;
            if (ptr == n) break;
        }
        if (ptr == n) break;
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    cout << sum;
    return 0;
}