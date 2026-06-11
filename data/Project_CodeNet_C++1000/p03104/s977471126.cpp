#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

ll f(ll n)
{
    if ((n + 1) % 4 == 0)
        return 0;
    if ((n + 1) % 4 == 1)
        return n;
    if ((n + 1) % 4 == 2)
        return 1;
    if ((n + 1) % 4 == 3)
        return n ^ 1;
}

int main()
{
    ll a, b, fa, fb;
    cin >> a >> b;

    fa = f(a - 1);
    fb = f(b);

    ll ans = fa ^ fb;
    cout << ans << endl;
}