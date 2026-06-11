#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
   
typedef long long ll;
const int N = 100010;
int num[40];
ll a[N];

int main()
{
    int n;
    ll k;
    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i <= 39; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((a[j] >> i) & 1) {
                ++num[i];
            }
        }
    }
    ll ret = 0, ans = 0, now = 0;
    for (int i = 39; i >= 0; --i) {
        ll tmp1 = ret, tmp2 = now;
        now += (ll)num[i] * (1LL << i);
        for (int j = i - 1; j >= 0; --j) {
            if ((ret | (1LL << j)) > k) {
                now += (ll)num[j] * (1LL << j);
            } else {
                now += (ll)max(num[j], n - num[j]) * (1LL << j);
                if (n - num[j] > num[j]) ret += (1LL << j);
            }
        }
        ans = max(ans, now);
        ret = tmp1, now = tmp2;
        if ((k >> i) & 1) {
            ret += (1LL << i);
            now += (ll)(n - num[i]) * (1LL << i);
        }
    }
    printf("%lld\n", ans);
    return 0;
}