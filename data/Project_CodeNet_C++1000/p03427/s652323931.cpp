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
    lli N;
    cin >> N;
    int tmp = 0;
    int maxnum = -1;
    string s = to_string(N);
    for (int i = 0; i < s.length(); i++)
    {
        int d = s[i] - '0';
        if (i > 0 && d != 9)
        {
            tmp = 0;
            tmp += (s[0] - '0');
            tmp -= 1;
            for (int j = 1; j < s.length(); j++)
            {
                tmp += 9;
            }
            cout << tmp << endl;
            return 0;
        }
        tmp += d;
    }
    cout << tmp << endl;
    return 0;
}
