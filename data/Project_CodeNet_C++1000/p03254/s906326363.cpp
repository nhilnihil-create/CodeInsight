#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        if (x < a[i]) break;
        if (i == n - 1 && x != a[i]) break;
        x -= a[i];
        if (x >= 0) ++ans;
        else break;
    }
    cout << ans << endl;
    return 0;
}
