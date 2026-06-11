#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, t;

int main() {
    cin >> n >> m >> s >> t;
    for (int i = min(n, m); i; i--) {
        if (!(n % i) && !(m % i)) {
            long long len = 1LL * n * m / i;
            bool flag = 1;
            int t1 = len / n, t2 = len / m;
            long long lcm = 1LL * t1 * t2 / __gcd(t1, t2);
            for (long long j = 0; j < len; j += lcm) {
                flag &= (s[j / t1] == t[j / t2]);
            }
            if (flag) { cout << len << endl; exit(0); }
        }
    }
    cout << -1 << endl;
    return 0;
}