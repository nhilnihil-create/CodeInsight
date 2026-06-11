#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
#include <stack>
//#include <atcoder/scc>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
//using namespace atcoder;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
}

lli gcd2(lli x, lli y)
{
    lli t;
    while (y != 0)
        t = x % y, x = y, y = t;
    return (x);
}

lli lcm2(lli x, lli y)
{
    lli xy = x * y;
    if (xy < 0)
        xy = -xy;
    return (xy / gcd2(x, y));
}
lli m = 1e9 + 7;
int main(void)
{
    int a, b;
    cin >> a >> b;
    cout << max(a * b, max(a - b, a + b)) << endl;
    return 0;
}
