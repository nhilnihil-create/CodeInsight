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
    int q;
    ll a, b;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        ll c = (ll)sqrtl(a * b - 1), z = c + c;
        if (a <= c) z--;
        if (b <= c) z--;
        if (c * (c + 1) >= a * b) z--;
        cout << z << '\n';
    }
}
