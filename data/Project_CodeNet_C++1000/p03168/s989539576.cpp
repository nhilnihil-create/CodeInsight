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

// long long expo(long long a, long long b, long long m)
// {
//     ll ret = 1;
//     while (b > 0)
//     {
//         if (b % 2 == 1)
//             ret = ((ret % m) * (a % m)) % m;
//
//         a = (a % m) * (a % m);
//         b = b / 2;
//     }
//     return ret;
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

    int n, i, j;
    cin >> n;

    vector<double> Ph(n);
    vector<double> dp(n + 1);
    dp[0] = 1;

    for (i = 0; i < n; i++)
        cin >> Ph[i];

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j >= 0; --j)
        {
            if (j == 0)
                dp[j] = dp[j] * (1 - Ph[i]);
            else
                dp[j] = (dp[j - 1] * (Ph[i])) + (dp[j] * (1 - Ph[i]));
        }
    }

    double ans = 0;
    for (i = 0; i <= n; i++)
    {
        if (n - i < i)
            ans = ans + dp[i];
    }
    cout << fixed << setprecision(10) << ans << endl;
}
