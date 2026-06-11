#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n, k;
    cin >> n >> k;

    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        int p = 0;
        int j = i;
        while (j < k) {
            j *= 2;
            ++p;
        }
        ans += pow(0.5, p);
    }

    ans *= 1.0 / n;

    cout << ans << '\n';

    return 0;
}