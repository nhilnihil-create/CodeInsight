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
    int n, c[22] = {}, v[22] = {}, z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < (1 << n); i++) {
        int x = 0, y = 0;
        for (int j = 0; j < n; j++) if (i & (1 << j)) x += c[j], y += v[j];
        z = max(z, x - y);
    }
    cout << z;
}
