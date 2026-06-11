#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (((a) * (b)) / (__gcd((a), (b))))
#define in_range(x, y, r, c) (x < r && y < c && x >= 0 && y >= 0)
#define setbits(x) __builtin_popcountll(x)
#define unsetend(x) __builtin_ctzll(x)
#define unsetfront(x) __builtin_clzll(x)
#define f first
#define s second
#define pb push_back
#define pf push_front
#define ll long long
#define endl "\n"
#define Endl "\n"

// long long expo(long long a, long long b, long long mod)
// {
//     ll ret = 1;
//     while (b > 0)
//     {
//         if (b % 2 == 1)
//             ret = (((ret)%mod) * ((a)%mod))%mod;
//
//         a = ((a)%mod) * ((a)%mod)%mod;
//         b = b / 2;
//     }
//     return (ret%mod);
// }

// vector<long long> seive()
// {
//    long long i,j;
//    vector<long long> hash(1000001,1);
//    vector<long long> primes;
//
//    for(i=2;i*i<=1000000;i++)
//    {
//        if(hash[i])
//        {
//            for(j=i*i;j<=1000000;j+=i)
//            hash[j]=0;
//        }
//    }
//    for(i=2;i<1000001;i++)
//    {
//        if(hash[i])
//        primes.pb(i);
//    }
//    return primes;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    string str1, str2, ans = "";
    cin >> str1;
    cin >> str2;

    int l1 = str1.size(), l2 = str2.size(), n;
    int dp[l1 + 1][l2 + 1];

    for (i = 0; i <= l1; i++)
    {
        for (j = 0; j <= l2; j++)
            dp[i][j] = 0;
    }

    for (i = 1; i <= l1; i++)
    {
        for (j = 1; j <= l2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // for (i = 0; i <= l1; i++)
    // {
    //     for (j = 0; j <= l2; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    int l = dp[l1][l2];
    i = l1;
    j = l2;
    while (l)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans.pb(str1[i - 1]);
            i--;
            j--;
            l--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
