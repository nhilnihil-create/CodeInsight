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
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1] && s[i] == '0')
        {
            s[i + 1] = '1';
            cnt++;
        }
        else if (s[i] == s[i + 1] && s[i] == '1')
        {
            s[i + 1] = '0';
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
