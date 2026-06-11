#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;
int mop(int x, int y)
{
    int res = 1;
    while (y > 0)
        res *= x, --y;
    return res;
}
void solve(void)
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int res;
    if (a > b && a > c)
        res = a * mop(2, k) + b + c;
    else if (b > a && b > c)
        res = b * mop(2, k) + a + c;
    else
        res = c * mop(2, k) + a + b;
    cout << res << endl;
}
int main(void)
{
    solve();
}