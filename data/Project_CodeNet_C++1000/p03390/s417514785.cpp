#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second
 
using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;
 
llong get_max(llong A2, llong B1) {
    llong ret = A2 * B1;
    llong x = (A2 + B1) / 2;
    llong y = A2 + B1 - x;
    if (x <= A2 && B1 <= y) ret = max(ret, x * y);
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int s = 0, e = b - 1;
        while (s < e) {
            int m = (s + e + 1) / 2;
            if (get_max(m, a + 1) < (llong)a * b) s = m;
            else e = m - 1;
        }
        printf("%d\n", a - 1 + s);
    }
    return 0;
}