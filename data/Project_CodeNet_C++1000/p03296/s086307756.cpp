#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; )
    {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        ans += (j - i) / 2;
        i = j;
    }
    cout << ans;
}
