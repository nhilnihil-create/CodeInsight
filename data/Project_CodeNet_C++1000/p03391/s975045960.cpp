#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool diff = false;
    long long ans = 0;
    int big = 1E9 + 6;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ans += a;
        if (a > b && b < big)
            big = b;
        diff = diff || (a != b);
    }
    ans -= big;
    if (!diff)
        ans = 0;
    cout << ans << endl;
    return 0;
}
