#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;
void solve(void)
{
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    int x = max(a1, max(a2, a3));
    int y = min(a1, min(a2, a3));
    cout << abs(x - y) << endl;
}
int main(void)
{
    solve();
}