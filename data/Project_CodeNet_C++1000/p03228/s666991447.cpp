#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define repr(i, n) for (ll i = n - 1; i >= 0; --i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve(void)
{
    int a, b, k;
    cin >> a >> b >> k;
    rep(i, k)
    {
        if (i % 2)
        {

            if (b % 2 == 1)
                --b;
            a += b / 2, b /= 2;
        }
        else
        {
            if (a % 2 == 1)
                --a;
            b += a / 2, a /= 2;
        }
    }
    cout << a << " " << b << endl;
}
int main(void)
{
    solve();
}