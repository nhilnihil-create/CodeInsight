#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;
void solve(void)
{
    int a, b;
    cin >> a >> b;
    int ans = INF;
    for (int i = 1; i < 999; ++i)
    {
        int x = i * (i + 1) / 2;
        int y = x + i + 1;
        if (x - a == y - b)
            ans = min(ans, x - a);
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}