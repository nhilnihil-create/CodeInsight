#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int R;
    cin >> R;
    if (R < 1200)
    {
        cout << "ABC" << endl;
    }
    else if (R >= 1200 && R < 2800)
    {
        cout << "ARC" << endl;
    }
    else
    {
        cout << "AGC" << endl;
    }
    return 0;
}