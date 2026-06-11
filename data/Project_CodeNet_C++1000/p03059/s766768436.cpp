#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, t;
    cin >> a >> b >> t;

    int ans = 0;
    for (int i = 1; i * a < t + 0.5; i++)
        ans += b;
    cout << ans << endl;
    return 0;
}