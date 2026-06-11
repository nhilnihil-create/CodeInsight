#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long s;
    cin >> s;
    int ans = 11111110;
    while (s >= 100)
    {
        int r = s % 1000;
        ans = min(ans, abs(r - 753));
        s /= 10;
    }
    cout << ans << endl;
    return 0;
}