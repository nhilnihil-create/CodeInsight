#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans;
    if (k % 2 == 1)
        ans = pow(n / k, 3);
    else
        ans = pow(n / k, 3) + pow((n + k / 2) / k, 3);
    cout << ans << endl;
}