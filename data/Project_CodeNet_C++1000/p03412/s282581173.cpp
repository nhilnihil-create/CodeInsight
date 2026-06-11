#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    for (int e = 1 << 29; e > 0; e >>= 1) {
        long long c = 0;
        if (n % 2 != 0) {
            int s = 0, t = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] & e) c++;
                if (b[i] & e) c++;
            }
        }
        // count carries
        for (int i = 0; i < n; i++) { a[i] &= e-1; b[i] &= e-1; }
        sort(a, a+n); sort(b, b+n);
        for (int i = 0, j = n-1; i < n; i++) {
            if (a[i] + b[n-1] < e) continue;
            while (j >= 0 && a[i] + b[j] >= e) j--;
            j++;
            c += n - j;
        }
        if (c % 2 != 0) ans += e;
    }
    cout << ans << endl;
}
