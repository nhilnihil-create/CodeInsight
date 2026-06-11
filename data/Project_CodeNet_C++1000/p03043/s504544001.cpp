#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    double ans = 0;
    repl(i, 1, n + 1) {
        double p = 1;
        int x = i;
        while(x < k) {
            p *= 0.5;
            x *= 2;
        }
        ans += p / n;
    }
    cout << setprecision(15) << ans << endl;
    return 0;
}
