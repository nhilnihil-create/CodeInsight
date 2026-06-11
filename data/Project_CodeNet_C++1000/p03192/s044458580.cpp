#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N;
    cin >> N;
    int tmp = 1;
    int count = 0;
    if ((N / tmp) % 10 == 2)
    {
        count++;
    }
    for (int i = 0; i < 3; i++)
    {
        tmp *= 10;
        if ((N / tmp) % 10 == 2)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}