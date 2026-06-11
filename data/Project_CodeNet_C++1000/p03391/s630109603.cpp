#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll INF = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    ll mi = INF;
    for(int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        ans += a;
        if(a > b) mi = min(mi, b);
    }
    if(mi == INF) cout << 0 << endl;
    else cout << ans - mi << endl;
}
