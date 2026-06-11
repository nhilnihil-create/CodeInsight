#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 1, bd = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans *= 3;
        if (a[i] % 2 == 0) bd *= 2;
    }
    cout << ans - bd;
}
