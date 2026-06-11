#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
//input
int main(void)
{
    int N;
    cin >> N;
    string s;
    int ans = 1000000;
    int tmp = 0;
    for (int i = 1; i < N; i++)
    {
        s = to_string(i);
        for (int j = 0; j < s.length(); j++)
        {
            int k = s[j] - '0';
            tmp += k;
        }
        s = to_string(N - i);
        for (int j = 0; j < s.length(); j++)
        {
            int k = s[j] - '0';
            tmp += k;
        }
        ans = min(ans, tmp);
        tmp = 0;
    }
    cout << ans << endl;
    return 0;
}
