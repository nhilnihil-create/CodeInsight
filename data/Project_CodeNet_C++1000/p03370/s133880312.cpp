#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    int sum = 0, mn = 1e9;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        mn = min(mn, a);
    }

    cout << n + (x - sum) / mn;

    return 0;
}
