#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    ll ans = 1145141919810;
    for (int i = 0; i <= n - k; i++)
    {
        if (x[i] < 0 && x[i + k - 1] > 0)
            ans = min(ans, max(abs(x[i]),abs(x[i + k - 1])) + 2 * min(abs(x[i]),abs(x[i + k - 1])));
        else
            ans = min(ans, max(abs(x[i]), abs(x[i + k - 1])));
    }
    cout << ans << endl;
}