#include <bits/stdc++.h>
using namespace std;

int f(int x)
{
    if (!x)
    {
        return 0;
    }
    return f(x / 10) + x % 10;
}

int main()
{
    int n;
    cin >> n;
    int ans = 100000;
    for (int i = 1; i <= n - 1; i++)
    {
        ans = min(ans, f(i) + f(n - i));
    }
    cout << ans << endl;
    return 0;
}