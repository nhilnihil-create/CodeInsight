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
    int n, a[200005] = {}, b[200005] = {}, w = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(b + 1, b + n + 1);
    for (int i = 0; i < 29; i++) {
        int c[200005] = {}, z = 0;
        for (int j = 1; j <= n; j++) c[j] = b[j] % (1 << (i + 1));
        sort(c + 1, c + n + 1);
        for (int j = 1; j <= n; j++) {
            int d = a[j] % (1 << (i + 1));
            z += n + 1 - (int)(lower_bound(c + 1, c + n + 1, 3 * (1 << i) - d) - c);
            z -= n + 1 - (int)(lower_bound(c + 1, c + n + 1, 2 * (1 << i) - d) - c);
            z += n + 1 - (int)(lower_bound(c + 1, c + n + 1, 1 * (1 << i) - d) - c);
            z %= 2;
        }
        if (z) w += (1 << i);
    }
    cout << w;
}
