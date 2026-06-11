#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL maxn = 2e3 + 100, max_val = 4e6 + 10;
LL n, a[maxn], sum;

void read() {
    scanf("%lld", &n);
    for (LL i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
}

LL solve() {
    bitset<max_val> bs;
    bs.reset();
    bs.set(0);
    for (LL i = 1; i <= n; ++i)
        bs |= (bs << a[i]);
    for (LL val = sum / 2; val >= 0; --val)
        if (bs.test(val))
            return sum - val;
}

int main() {
    read();
    cout << solve() << endl;
}
