#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int x, y, z, k;
    ll a[1003] = {}, b[1003] = {}, c[1003] = {}, l = 0, r = mod * 328ll;
    cin >> x >> y >> z >> k;
    for (int i = 0; i < x; i++) cin >> a[i];
    for (int i = 0; i < y; i++) cin >> b[i];
    for (int i = 0; i < z; i++) cin >> c[i];
    sort(a, a + x); sort(b, b + y); sort(c, c + z);
    a[x] = b[y] = c[z] = mod * 328ll;
    while (l + 1 < r) {
        ll m = (l + r) >> 1;
        int w = 0;
        for (int i = 0; i < x; i++) for (int j = 0; j < y; j++) if (a[i] + b[j] <= m) w += (int)(lower_bound(c, c + z + 1, m - a[i] - b[j] + 1) - c);
        if (x * y * z - w >= k) l = m;
        else r = m;
    }
    vector<ll> v;
    for (int i = 0; i < x; i++) for (int j = 0; j < y; j++) {
        int w = (int)(lower_bound(c, c + z + 1, r - a[i] - b[j]) - c);
        for (int k = w; k < z; k++) v.push_back(a[i] + b[j] + c[k]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < k; i++) cout << v[i] << '\n';
    return 0;
    int T;
    cin >> T;
    for (int U = 1; U <= T; U++) {
        cout << "Case #" << U << ": ";
        
    }
}
