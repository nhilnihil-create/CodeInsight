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
    int n, a[280000] = {}, z = 0;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) cin >> a[i];
    for (int i = 1; i < (1 << n); i++) {
        vector<int> b;
        for (int j = 0; j < n; j++) if (i & (1 << j)) b.push_back(j);
        int m = (int)b.size(), d[18] = {}, c = 0, x = a[0], y = 0;
        for (int j = 1; j < (1 << m); j++) {
            int e = __builtin_ctz(j);
            if (!d[e]) d[e] = 1, c += 1 << b[e];
            else d[e] = 0, c -= 1 << b[e];
            if (a[c] > x) y = x, x = a[c];
            else if (a[c] > y) y = a[c];
        }
        z = max(z, x + y);
        cout << z << '\n';
    }
}
