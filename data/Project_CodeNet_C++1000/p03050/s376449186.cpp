//#define ONLINE_JUDGE
#define rush()        \
    int MYTESTNUM;    \
    cin >> MYTESTNUM; \
    while (MYTESTNUM--)
#define FOR(i, s, t) for (int i = (s); i <= (t); ++i)
#define mem(a, b) memset(a, b, sizeof(a))
#define pi acos(-1)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1 << 30;
const double eps = 1e-8;
ll n;
vector<ll> ans;
void divisor(ll n)
{
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) {
                ans.push_back(n / i);
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    divisor(n);
    ll tot = 0;
    for (auto& i : ans) {
        ll x = n / i, m = (n - x) / x;
        if (m > 0 && n % m == n / m) {
            tot += m;
        }
    }
    cout << tot;
}