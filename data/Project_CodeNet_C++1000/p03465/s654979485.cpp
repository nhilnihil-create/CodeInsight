#include<bits/stdc++.h>
using namespace std;

bool dp[2000009];

int main()
{
    int n, i, j, a[2009], sum = 0;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+n);

    dp[0] = 1;

//    for(i = 0; i <= sum/2; i++)
//        dp[i][0] = 0;
//    for(i = 0; i <= n; i++)
//        dp[0][i] = 1;

    for(i = 0; i < n; i++)
    {
        for(j = sum/2; j >= a[i]; j--)
        {
            dp[j] |= dp[j - a[i]];
        }
    }

//    for(i = 0; i <= sum/2; i++)
//    {
//        cout << dp[i];
//        cout << endl;
//    }

    for(i = sum/2; i >= 0; i--)
    {
        if(dp[i])
        {
            cout << sum - i;
            return 0;
        }
    }
}
