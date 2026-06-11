# include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int INF = 1000000005;
const int MOD = 998244353;
typedef long long i64;

i64 _sqrt(i64 x) {
    i64 l = 1, r = INF, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (l == mid) break;
        if (mid * mid <= x) l = mid;
        else r = mid;
    }
    return l;
}
int main ()
{
    i64 Q, a, b;
    cin >> Q;
    while (Q--) {
        cin >> a >> b;
        if (a == 1 && b == 1) {puts("0"); continue;}
        i64 x = a * b - 1, cnt = 0;
        i64 m = _sqrt(x);
        if (m == x / m) ++cnt;
        i64 p = (x / m - m);
        if (a > m && a <= x && x / (x / a) == a) {
            i64 k = x / a;
            if (k + 1 < m && x / (k + 1) < a - 1) ;
            else if (p) --p;
            else ++cnt;
        }
        if (b > m && b <= x && x / (x / b) == b) {
            i64 k = x / b;
            if (k + 1 < m && x / (k + 1) < b - 1) ;
            else if (p) --p;
            else ++cnt;
        }
        if (a > m && b > m) printf("%lld\n", 2 * m - cnt);
        else printf("%lld\n", 2 * m - 1 - cnt);
    }
    return 0;
}
