#include "bits/stdc++.h"

using namespace std;

int a[2010];
bitset<4000010> dp(1);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp |= (dp << a[i]);
    }
    for (int i = 1; i <= 4000000; i++)
    {
        if (dp[i] && 2 * i >= sum)
        {
            cout << i << endl;
            return 0;
        }
    }
}
