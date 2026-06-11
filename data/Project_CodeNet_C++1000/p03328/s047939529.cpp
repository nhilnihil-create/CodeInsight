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
    int a, b;
    cin >> a >> b;
    //cout << b - a << endl;
    int A[1000];
    fill(A, A + 1000, 0);
    A[0] = 1;
    for (int i = 1; i <= 999; i++)
    {
        A[i] = A[i - 1] + (i + 1);
    }
    for (int i = 0; i < 999; i++)
    {
        if (A[i + 1] - A[i] == b - a)
        {
            cout << A[i] - a << endl;
            return 0;
        }
    }
    return 0;
}
