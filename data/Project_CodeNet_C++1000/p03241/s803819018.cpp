#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

vector<int> divisor(int n)
{
    vector<int> res;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (n % (n / i) == 0)
                res.push_back(n / i);
        }
    }
    return res;
}
void solve(void)
{
    ll n, m;
    cin >> n >> m;
    int ans = 0;
    for (auto i : divisor(m))
    {
        if (n * i <= m)
            ans = max(ans, i);
    }
    cout << ans << endl;
}
int main(void) { solve(); }
