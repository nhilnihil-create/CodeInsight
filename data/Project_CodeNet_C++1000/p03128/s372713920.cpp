#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, a[10] = {}, c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, d[10004] = {};
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m); reverse(a, a + m);
    for (int i = 1; i <= n; i++) {
        d[i] = -10004;
        for (int j = 0; j < m; j++) if (i >= c[a[j]]) d[i] = max(d[i], d[i - c[a[j]]] + 1);
    }
    while (n) {
        for (int i = 0; i < m; i++) if (n >= c[a[i]] && d[n - c[a[i]]] + 1 == d[n]) {
            cout << a[i];
            n -= c[a[i]];
            break;
        }
    }
}
