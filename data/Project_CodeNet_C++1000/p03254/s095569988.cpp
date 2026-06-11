#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)
#define int long long

const int maxn = 5e5 + 1, CC = 10001;

using namespace std;

int a[100];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            cout << i;
            return 0;
        }
        if (i == n - 1 && a[i] < x) {
            cout << i;
            return 0;
        }
        x -= a[i];
    }
    cout << n;
    return 0;
}
