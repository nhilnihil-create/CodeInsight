#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn], pref[maxn], f[2 * maxn];

inline void add(int x) {
    while (x < 2 * maxn) {
        f[x]++;
        x = (x|(x + 1));
    }
}

inline int get(int x) {
    int ans = 0;
    while (x > 0) {
        ans += f[x];
        x = (x&(x + 1)) - 1;
    }
    return ans;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    sort(b + 1, b + n + 1);
    int lef = 0, righ = n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += (n - i + 1);
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        for (int j = 1; j <= n; ++j) {
            if (a[j] <= b[mid]) c[j] = 1;
            else c[j] = -1;
            pref[j] = pref[j - 1] + c[j];
        }
        int cnt = 0;
        for (int i = 0; i < 2 * maxn; ++i) f[i] = 0;
        add(maxn + 1);
        for (int j = 1; j <= n; ++j) {
            cnt += get(pref[j] + maxn);
            add(pref[j] + 1 + maxn);
        }
        if (cnt >= (sum + 2) / 2) righ = mid;
        else lef = mid;
    }
    cout << b[righ] << '\n';
    return 0;
}

