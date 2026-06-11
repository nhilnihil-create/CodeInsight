#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> diff(n);
    rep (i, n)
    {
        int temp;
        cin >> temp;
        diff[i] = abs(x - temp);
    }

    int ans = diff[0];
    for (int i = 1; i < n; i++)
        ans = gcd(ans, diff[i]);

    cout << ans << endl;
    return 0;
}