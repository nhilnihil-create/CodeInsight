#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll INF = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[0] != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] > a[i-1] + 1)
        {
            cout << -1 << endl;
            return 0;
        }
        ans += a[i];
        if(a[i] == a[i-1] + 1) ans -= a[i-1];
    }
    cout << ans << endl;
}
