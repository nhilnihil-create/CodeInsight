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
    int n, x[1003] = {}, y[1003] = {}, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 1; i < n; i++) if (abs(x[i] + y[i]) % 2 != abs(x[0] + y[0]) % 2) {
        cout << -1;
        return 0;
    }
    if ((x[0] + y[0]) % 2 == 0) {
        cout << 32 << '\n';
        for (int i = 30; i >= 0; i--) cout << (1 << i) << ' '; cout << 1 << '\n';
        for (int i = 0; i < n; i++) x[i]--;
        b = 1;
    } else {
        cout << 31 << '\n';
        for (int i = 30; i >= 0; i--) cout << (1 << i) << ' '; cout << '\n';
    }
    for (int i = 0; i < n; i++) {
        int u = 0, v = 0;
        for (int j = 30; j >= 0; j--) {
            if (x[i] - u > y[i] - v && x[i] - u > v - y[i]) u += (1 << j), cout << 'R';
            else if (x[i] - u > y[i] - v && x[i] - u < v - y[i]) v -= (1 << j), cout << 'D';
            else if (x[i] - u < y[i] - v && x[i] - u > v - y[i]) v += (1 << j), cout << 'U';
            else if (x[i] - u < y[i] - v && x[i] - u < v - y[i]) u -= (1 << j), cout << 'L';
            else return 1;
        }
        if (b) cout << 'R';
        cout << '\n';
    }
}
