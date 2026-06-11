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
    int N, M;
    cin >> N;
    map<int, int> x, y;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        x[tmp]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        y[tmp]++;
        if (y[tmp] > x[tmp])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
