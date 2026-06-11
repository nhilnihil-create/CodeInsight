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
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int K;
    cin >> K;
    sort(a, a + 3);
    for (int i = 0; i < K; i++)
    {
        a[2] *= 2;
    }
    cout << a[0] + a[1] + a[2] << endl;
    return 0;
}