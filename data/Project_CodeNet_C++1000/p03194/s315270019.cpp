#include <bits/stdc++.h>

#define int long long

using namespace std;

bool prime[2000100];

int32_t main()
{
    int n,p;
    cin >> n >> p;

    if(n == 1)
    {
        cout << p << endl;
        return 0;
    }

    int ans = 1;

    for(int i=2;i*i<=p;i++)
    {
        int cnt = 0;
        int t = p;

        while(t%i == 0)
            t /= i, cnt++;

        cnt /= n;

        if(cnt)
            ans = i;
    }

    cout << ans << endl;

    // if(n > 50)
    // {
    //     cout << 1 << endl;
    //     return 0;
    // }

    // prime[0] = prime[1] = true;

    // for(int i=2;i*i<=2000100;i++)
    // {
    //     if(!prime[i])
    //     {
    //         for(int j=i*i;j<2000100;j+=i)
    //             prime[j] = true;
    //     }
    // }

    // int ans =  1;

    // for(int i=2;i*i<=p;i++)
    // {
    //     if(!prime[i] && p%i == 0)
    //     {
    //         int cnt = 0;

    //         while(p%i == 0)
    //             p /= i, cnt++;

    //         cnt /= n;

    //         if(cnt > 0)
    //             ans = max(ans,ans*i*cnt);
    //     }
    // }

    // cout << ans << endl;
}