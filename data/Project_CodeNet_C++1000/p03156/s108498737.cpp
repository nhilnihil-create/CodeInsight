#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i =0 ; i < n; i++)
    {
        int p;
        cin >> p;
        if (p <= a) c0++;
        if (a < p && p <= b) c1++;
        if (b < p) c2++;
    }
    cout << min(min(c1, c0), c2);
}
