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
    int N, X;
    cin >> N >> X;
    int m[N];
    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
    }
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        sum += m[i];
    }
    X = X - sum;
    cnt += N;
    sort(m, m + N);
    while (X >= m[0])
    {
        X -= m[0];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
