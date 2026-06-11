#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    rep(i, n)
    {
        ll a;
        cin >> a;
        ans += a - 1;
    }
    cout << ans << endl;
}