#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    rep (i, n)
        cin >> a[i];

    int ans = a[0];
    for (int i = 1; i < n; i++)
        ans = gcd(ans, a[i]);

    cout << ans << endl;
    return 0;
}