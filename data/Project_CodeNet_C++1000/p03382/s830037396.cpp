#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Num[100005], Max, Min = 987654321, result;

int abs(int num)
{
    return num > 0 ? num : -num;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Num[i]);
        Max = max(Max, Num[i]);
    }
    for(int i = 0; i < N; i++)
    {
        if(Max == Num[i])
        {
            continue;
        }
        if(Min > abs(Num[i] - (Max - Num[i])))
        {
            Min = abs(Num[i] - (Max - Num[i]));
            result = Num[i];
        }
    }
    printf("%d %d", Max, result);
}