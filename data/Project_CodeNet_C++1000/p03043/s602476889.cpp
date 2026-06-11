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
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
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

int main(void)
{
    //i*2^x >= K
    //2^x>=K/i
    //x >= log2(K/i)
    int N, K;
    cin >> N >> K;
    double ans = 0.0;
    double ini = (double)(1.0 / (double)N);
    int powarray[21];
    for (int i = 0; i <= 20; i++)
    {
        powarray[i] = (int)(pow(2, i + 1));
    }
    bool f = false;
    for (int i = 1; i <= N; i++)
    {
        if (i < K)
        {
            for (int j = 0; j <= 20; j++)
            {
                if (i * powarray[j] >= K)
                {
                    ans += ini * pow(0.5, j + 1);
                    break;
                }
            }
        }
        else
        {
            ans += ini;
        }
    }
    printf("%.13f", ans);
    return 0;
}
