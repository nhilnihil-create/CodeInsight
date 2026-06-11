#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, a, b;

int main() {
    scanf("%lld", &T);
    while (T--) {
        ll ans = 0;
        scanf("%lld%lld", &a, &b);
        if (a == b) ans = 2 * (a - 1);
        else {
            ll tmp = sqrt(a * b);
            if (tmp * tmp == a * b) tmp--;
            if (tmp * (tmp + 1) >= a * b) ans = 2 * (tmp - 1);
            else ans = 2 * tmp - 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
