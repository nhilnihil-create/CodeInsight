#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> x(n+2);
    vector<ll> v(n+2);
    x[0] = 0;
    v[0] = 0;
    x[n+1] = c;
    v[n+1] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> v[i];
    }

    vector<ll> fa(n+1);
    vector<ll> fb(n+1);
    for(int i = 1; i <= n; i++)
    {
        fa[i] = fa[i-1] + v[i] - x[i] + x[i-1];
    }
    for(int i = 1; i <= n; i++)
    {
        fb[i] = fb[i-1] + v[n+1-i] - abs(c-x[n+1-i]) + abs(c-x[n+2-i]);
    }
    vector<ll> ma(n+1);
    vector<ll> mb(n+1);
    for(int i = 1; i <= n; i++)
    {
        ma[i] = max(ma[i-1], fa[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        mb[i] = max(mb[i-1], fb[i]);
    }

    ll ans = 0;
    // 0->a->0->b
    for(int i = 0; i <= n; i++)
    {
        ans = max(ans, fa[i] - x[i] + mb[n-i]);
    }
    // 0->b->0->a
    for(int i = 0; i <= n; i++)
    {
        ans = max(ans, fb[i] - abs(c-x[n+1-i]) + ma[n-i]);
    }
    cout << ans << endl;
}
