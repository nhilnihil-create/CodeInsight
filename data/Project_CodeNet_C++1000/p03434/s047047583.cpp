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
    int N;
    cin >> N;
    vector<int> a;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int A = 0;
    int B = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            A += a[i];
        }
        else
        {
            B += a[i];
        }
    }
    cout << A - B << endl;
    return 0;
}
