
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d, n;

    cin >> d >> n;
    if (n == 100)
        n = 101;
    int ans = n * pow(100, d);
    cout << ans << endl;
    return 0;
}