#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int a[maxn], sum[maxn], pref[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pref[i] = (pref[i - 1]^a[i]);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; ++i) {
        int lef = i, righ = n + 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (sum[mid] - sum[i - 1] == (pref[mid]^pref[i - 1])) lef = mid;
            else righ = mid;
        }
        ans += (lef - i + 1);
    }
    cout << ans << '\n';
    return 0;
}

