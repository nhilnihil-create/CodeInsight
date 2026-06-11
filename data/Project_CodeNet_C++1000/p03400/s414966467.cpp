#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d, x;
    cin >> n >> d >> x;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ans += 1 + (d - 1) / a;
    }
    ans += x;

    cout << ans;

    return 0;
}
