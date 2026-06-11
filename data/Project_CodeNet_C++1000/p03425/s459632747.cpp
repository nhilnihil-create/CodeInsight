#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)

int main(void)
{
    //abc089c
    lli ans = 0;
    map<char, lli> x;
    lli N;
    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H')
        {
            x[s[0]]++;
        }
    }
    char a[5] = {'M', 'A', 'R', 'C', 'H'};
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                ans += x[a[i]] * x[a[j]] * x[a[k]];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
