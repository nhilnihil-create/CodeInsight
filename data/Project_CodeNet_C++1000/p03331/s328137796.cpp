#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d",&n);

    int a = 1, b = 1;
    int ans = 1000000;
    int s = 0, t = 0;
    for (int i = 1; i <= n/2; i++)
    {
        a = i;
        b = n - i;
        while (a > 0)
        {
            s +=  a % 10;
            a /= 10;
        }
        while (b > 0)
        {
            t += b % 10;
            b /= 10;
        }
        ans = min(ans, (s+t));
        s = 0;
        t = 0;   
    }

    printf("%d\n", ans);
}