#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll sol = 0;
    for (int b = k + 1; b <= n; ++b)
    {
        ll m = n;
        sol += (m / b) * (b - k);
        m %= b;
        m -= k - 1;
        sol += max(m, 0ll);
    }
    if (!k)
        sol -= n;
    cout << sol;
}
