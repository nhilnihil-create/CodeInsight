#include <bits/stdc++.h>
using namespace std;

bitset<2000 * 2000 + 10> b;

int main() {
    int n, x, s = 0;
    cin >> n; b.set(0);
    while (n--) {
        cin >> x; b |= (b << x), s += x;
    }
    for (int i = (s + 1) / 2; ; i++) {
        if (b.test(i)) printf("%d\n", i), exit(0);
    }
    return 0;
}