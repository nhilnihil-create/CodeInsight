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
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    lli cnt = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            /*for (int k = 0; k <= N; k++)
            {
                */
            int k = (int)((N - R * i - G * j) / B);
            if (R * i + G * j + B * k == N && k >= 0)
            {
                cnt++;
            } /*
            }*/
        }
    }
    cout << cnt << endl;
    return 0;
}
