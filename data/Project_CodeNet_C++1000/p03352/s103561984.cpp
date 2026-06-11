#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

int mop(int x, int y)
{
    int res = 1;
    while (y > 0)
        res *= x, --y;

    return res;
}
using namespace std;
void solve(void)
{
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 2; i <= 10; ++i)
        rep(j, 1000) if (mop(j, i) <= x) ans = max(ans, mop(j, i));
    cout << ans << endl;
}
int main(void)
{
    solve();
}