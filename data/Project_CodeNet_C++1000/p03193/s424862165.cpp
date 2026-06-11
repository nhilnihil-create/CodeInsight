#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0, h, w;
    cin >> n >> h >> w;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ans += (a >= h && b >= w);
    }
    cout << ans;
}
