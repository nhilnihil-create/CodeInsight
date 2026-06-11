#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define String std::string
#define fi first
#define se second
#define mp std::make_pair
#define Pair std::pair<int, int>
#define Map std::map< int, int >
#define Vector std::vector<int>

using std::cin;
using std::cout;
using std::endl;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100000 + 5;
const int M = 3000 + 5;
const int K = 1e7 + 5;
const int MOD = 1e9 + 7;
const int inv2 = 500000004;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
const double PI = acos(-1);

template<class T>
inline T readT() {
    T res = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) res = (res << 1) + (res << 3) + ch - '0';
    return res * f;
}
#define read readT<int>

int n, m, q;
ll a[N], b[N];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
    while (q--) {
        ll x;
        scanf("%lld", &x);
        int ua, ub, da, db;
        ll u, d, ans = LLONG_MAX;
        ua = std::lower_bound(a + 1, a + n + 1, x) - a;
        ub = std::lower_bound(b + 1, b + m + 1, x) - b;
        // if (ua != 1) da = ua - 1;
        // if (ub != 1) db = ub - 1;
        da = ua - 1;
        db = ub - 1;
        if (ua != n + 1 && ub != m + 1) {
            u = std::max(a[ua], b[ub]) - x;
        } else {
            u = LLONG_MAX;
        }
        if (da != 0 && db != 0) {
            d = x - std::min(a[da], b[db]);
        } else {
            d = LLONG_MAX;
        }

        ans = std::min(u, d);

        if (da != 0 && ub != m + 1) {
            ll t1 = (x - a[da]) * 2 + b[ub] - x;
            ll t2 = (b[ub] - x) * 2 + x - a[da];
            ans = std::min(ans, std::min(t1, t2));
        }

        if (db != 0 && ua != n + 1) {
            ll t1 = (x - b[db]) * 2 + a[ua] - x;
            ll t2 = (a[ua] - x) * 2 + x - b[db];
            ans = std::min(ans, std::min(t1, t2));
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}