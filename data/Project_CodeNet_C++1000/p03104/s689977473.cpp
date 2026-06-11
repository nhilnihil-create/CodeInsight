#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int a, b, ans = 0;
    cin >> a >> b;
    int l = a + (4 - a % 4) % 4, r = b - b % 4;
    for (int i = a; i < l; ++i)
        ans ^= i;

    for (int i = r; i <= b; ++i)
        ans ^= i;

    cout << ans;
}