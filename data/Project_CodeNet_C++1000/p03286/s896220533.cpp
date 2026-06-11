#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

void solve(void)
{
    ll n;
    cin >> n;
    vector<int> ans;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    while (n != 0)
    {
        int res;
        if (n > 0)
        {
            res = n % 2;
            n = -(n / 2);
        }
        else
        {
            res = abs(n) % 2;
            n = (abs(n) + 1) / 2;
        }
        ans.emplace_back(res);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i;
    cout << endl;
}
int main(void)
{
    solve();
}