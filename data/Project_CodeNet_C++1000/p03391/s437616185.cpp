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
    int n;
    ll a, b, z = 0, y = mod;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        z += a;
        if (a > b) y = min(y, b);
    }
    if (y == mod) cout << 0;
    else cout << z - y;
}
