// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int ma = max({a, b, c});
    int sum = a + b + c;

    int ans;
    if ((ma * 3 - sum) % 2 == 0)
    {
        ans = (ma * 3 - sum) / 2;
    }
    else
    {
        while (((ma * 3 - sum) % 2))
        {
            ma++;
        }
        ans = (ma * 3 - sum) / 2;
    }
    cout << ans << endl;
    return (0);
}
