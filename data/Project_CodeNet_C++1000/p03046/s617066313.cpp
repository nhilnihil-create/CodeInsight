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
    int m, k, z[270000] = {};
    cin >> m >> k;
    if (k >= (1 << m)) {cout << -1; return 0;}
    if (m == 1) {
        if (k == 0) cout << "0 0 1 1";
        else cout << -1;
        return 0;
    }
    for (int i = 0; i < (1 << m); i++) if (i != k) cout << i << ' ';
    cout << k << ' ';
    for (int i = (1 << m) - 1; i >= 0; i--) if (i != k) cout << i << ' ';
    cout << k;
}
