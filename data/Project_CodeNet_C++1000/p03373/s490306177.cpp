#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int k = min(x, y);
    long long ans = 0;
    ans += 1LL * k * min(a+b, 2*c);
    if(x < y) {
        int remy = y - x;
        ans += 1LL * remy * min(b, 2*c);
    }
    else {
        int remx = x - y;
        ans += 1LL * remx * min(a, 2*c);
    }
    cout << ans << endl;

    return 0;
}
