#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

LL a[100005];
LL b[100005];

LL hb (LL num)
{
    if (!num)
        return 0;

    int ret = 0;

    while (num >>= 1)
        ret ++;

    return ret;
}

int main() {
    LL n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    LL ans = 0;
    k++;
    for (LL h = hb(k); h >= 0; h--) {
        // printf("h = %lld\n", h);
        LL mx = (1 << h) & k;
        LL r = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < mx) {
                r += b[i];
            }
            if (a[i] & mx) {
                a[i] -= mx;
            }
        }
        // printf("r = %lld\n", r);
        ans = max(ans, r);
        k -= mx;
    }
    cout << ans << endl;
}
