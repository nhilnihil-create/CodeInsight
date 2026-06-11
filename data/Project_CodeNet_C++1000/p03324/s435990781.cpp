#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int d, n;
    cin >> d >> n;
    int ans = 0;
    if (d == 0)
    {
        if (n == 100)
            ans = n + 1;
        else
            ans = n;
    }
    if (d == 1)
    {
        if (n == 100)
            ans = n * 100 + 100;
        else
            ans = n * 100;
    }
    if (d == 2)
    {
        if (n == 100)
            ans = n * 10000 + 10000;
        else
            ans = n * 10000;
    }
    cout << ans << endl;
    return 0;
}