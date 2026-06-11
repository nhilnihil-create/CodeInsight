#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int gcd(int x, int y) {
    while (y) {
        int z = x % y;
        x = y;
        y = z;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    int n, a[100005] = {}, b[100005] = {}, z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    for (int i = 2; i <= n; i++) a[i] = gcd(a[i - 1], a[i]);
    for (int i = n - 1; i; i--) b[i] = gcd(b[i + 1], b[i]);
    for (int i = 1; i <= n; i++) z = max(z, gcd(a[i - 1], b[i + 1]));
    cout << z;
}
