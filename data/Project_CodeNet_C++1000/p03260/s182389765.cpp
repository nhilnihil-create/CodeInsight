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
    int A, B;
    cin >> A >> B;
    if (A % 2 == 0 || B % 2 == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}
