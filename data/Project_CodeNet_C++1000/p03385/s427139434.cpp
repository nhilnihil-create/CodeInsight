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
    string s;
    cin >> s;
    int cnta = 0, cntb = 0, cntc = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            cnta = 1;
        }
        if (s[i] == 'b')
        {
            cntb = 1;
        }
        if (s[i] == 'c')
        {
            cntc = 1;
        }
    }
    if (cnta == 1 && cntb == 1 && cntc == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
