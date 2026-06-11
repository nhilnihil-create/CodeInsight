#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;

int main()
{
    string s;
    cin >> s;

    s = 'a' + s;

    int flag = 0;
    int res = 100000;
    int n = s.size() - 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i + 1])
        {
            int tmp;
            tmp = max(i, n - i);
            res = min(res, tmp);
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << n;
    }
    else
    {
        cout << res;
    }

    return 0;
}