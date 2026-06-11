
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    scanf("%d", &x);
    vector<bool> isbeki(x + 1);
    isbeki[1] = true;
    for (int i = 2; i <= x; i++)
    {
        int v = i * i; //2乗
        while (v <= x)
        {
            isbeki[v] = true;
            v *= i; //3乗～増やしてく
        }
    }
    for (int i = x; i >= 1; i--)
    {
        if (isbeki[i])
        {
            printf("%d\n", i);
            return 0;
        }
    }
}