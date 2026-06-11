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
    ll ret = 0, ans = 0;
    for (int i = 39; i >= 0; --i) {
        if ((ret | (1LL << i)) > k) {
            ans += (ll)num[i] * (1LL << i);
        } else {
            ans += (ll)max(num[i], n - num[i]) * (1LL << i);
            if (n - num[i] > num[i]) ret += (1LL << i);
        }
    }
    printf("%lld\n", ans);
    return 0;
}