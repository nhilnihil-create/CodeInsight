#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = INT_MAX;

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    int n, m, c, x, ans = inf;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 1)
            c = i + 1;
    }
    for (int i = max(1, c - m + 1); i <= n; i++)
    {
        int l = i, r = i + m - 1;
        ans = min(ans, 1 + (l - 1) / (m - 1) + ((l - 1) % (m - 1) == 0? 0: 1) +
                           (n - r) / (m - 1) + ((n - r) % (m - 1) == 0? 0: 1));
    }
    cout << ans;
    return 0;
}