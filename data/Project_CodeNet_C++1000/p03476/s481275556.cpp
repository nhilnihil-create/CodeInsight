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

bool IsPrime(int num)
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main(void)
{
    int Q;
    cin >> Q;
    int l[Q], r[Q];
    for (int i = 0; i < Q; i++)
    {
        cin >> l[i] >> r[i];
    }
    int sum[100002];
    fill(sum, sum + 100002, 0);
    for (int i = 1; i <= 100001; i++)
    {
        if (i % 2 == 1)
        {
            if (IsPrime(i) == true && IsPrime((i + 1) / 2) == true)
            {
                sum[i] = sum[i - 1] + 1;
            }
            else
            {
                sum[i] = sum[i - 1];
            }
        }
        else
        {
            sum[i] = sum[i - 1];
        }
    }
    for (int i = 0; i < Q; i++)
    {
        cout << sum[r[i]] - sum[l[i] - 1] << endl;
    }
    return 0;
}
