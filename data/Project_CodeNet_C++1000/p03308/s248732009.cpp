#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int mn = 1e9, mx = -1e9;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    cout << mx - mn;

    return 0;
}
