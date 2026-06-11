#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    ll d;
    cin >> d;
    string ans = "Christmas ";
    rep(i, 0, 25 - d) ans += "Eve ";
    cout << ans << endl;
}
