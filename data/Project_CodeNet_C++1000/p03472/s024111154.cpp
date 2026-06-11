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
    int n, h, a[100005] = {}, b[100005] = {}, m = 0, d = 0;
    cin >> n >> h;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i], m = max(m, a[i]);
    sort(b, b + n);
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] < m) break;
        h -= b[i];
        d++;
        if (h <= 0) {
            cout << d;
            return 0;
        }
    }
    cout << d + (h - 1) / m + 1;
}
