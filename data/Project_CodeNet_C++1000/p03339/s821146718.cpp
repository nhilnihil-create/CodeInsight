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
    int N;
    cin >> N;
    string s;
    cin >> s;
    int cntE[N + 1];
    int cntW[N + 1];
    fill(cntE, cntE + N + 1, 0);
    fill(cntW, cntW + N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'W')
        {
            cntW[i + 1] = cntW[i] + 1;
            cntE[i + 1] = cntE[i];
        }
        else
        {
            cntE[i + 1] = cntE[i] + 1;
            cntW[i + 1] = cntW[i];
        }
    }
    int ans = 3000000;
    for (int i = 1; i <= N; i++)
    {
        //cout << cntW[i] << " " << cntE[i] << endl;
        int tmp = cntW[i - 1] + cntE[N] - cntE[i];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}