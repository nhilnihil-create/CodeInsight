#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;
void solve(void)
{
    int n;
    cin >> n;
    cout << 2 * n / __gcd(2, n) << endl;
}
int main(void)
{
    solve();
}