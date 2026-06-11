#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n , k;
    cin >> n >> k;

    vector<double> p(18);

    p[0] = 1;
    for (int i = 1 ;i < p.size() ;i++)
        p[i] = p[i - 1] / 2;

    double ans = 0;
    for (int i = 1 ;i <= n ;i++) {
        int cur = i , t = 0;
        while (cur < k)
            t++ , cur *= 2;

        ans += (1.0 / n) * p[t];
    }

    cout << fixed << setprecision(12) << ans;
}
