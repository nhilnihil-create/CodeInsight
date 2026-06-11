#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
int t;

int Sqrt(Long v) {
    int l = 0, r = 1e9, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (1ll * mid * mid <= v) {
            l = mid + 1; ans = mid;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        int a, b; scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        if (a == b) printf("%d\n", 2 * a - 2);
        else if (a + 1 == b) printf("%d\n", a * 2 - 2);
        else {
            int c = Sqrt(1ll * a * b - 1);
            if (1ll * c * (c + 1) >= 1ll * a * b) printf("%d\n", c * 2 - 2);
            else printf("%d\n", c * 2 - 1);
        }
    }
}
