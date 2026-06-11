#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int b = 1; b <= n; b++)
    {
        ans += (n / b) * max(0, b - 1 - k + 1);
        ans += max(0, (n % b) - k + 1);
    }
    if (k == 0)
        ans -= n;
    cout << ans << endl;
}