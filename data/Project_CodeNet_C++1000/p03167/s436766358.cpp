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

    int i, j, n, m, mod = 1e9 + 7;
    cin >> n >> m;
    char arr[n][m];
    int dp[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1; //up,left

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                if (arr[i][j] != '#')
                {
                    if (in_range(i - 1, j, n, m))
                        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                    if (in_range(i, j - 1, n, m))
                        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                }
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}
