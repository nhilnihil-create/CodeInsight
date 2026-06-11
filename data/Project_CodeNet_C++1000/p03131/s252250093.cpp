#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t k, a, b, x = 0;
    cin >> k >> a >> b;
    k++;
    if (a + 1 >= b) {
        cout << k << endl;
        return 0;
    }
    if (k >= a + 2) {
        x += b, k -= a + 2;
        x += (b - a) * (k / 2) + (k % 2);
    } else
        x += k;
    cout << x << endl;
    return 0;
}