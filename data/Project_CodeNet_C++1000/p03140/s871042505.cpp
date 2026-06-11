#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 2 * n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i] && b[i] == c[i]) ans -= 2;
        else if (a[i] == b[i] || b[i] == c[i] || c[i] == a[i]) ans--;
    }
    cout << ans;
}
