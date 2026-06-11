#include <bits/stdc++.h>

using namespace std;

long double t, x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> x;

    long double ans = t / x;

    cout << fixed << setprecision(10) << ans;

    return 0;
}
