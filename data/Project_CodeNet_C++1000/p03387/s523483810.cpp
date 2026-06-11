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

    cout << (((ma * 3 - sum) % 2 == 0) ? (ma * 3 - sum) / 2 : ((ma + 1) * 3 - sum) / 2) << '\n';
    return (0);
}
