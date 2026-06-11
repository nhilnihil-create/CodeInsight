#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

int n;
int x[1<<18];
int dp[18][1<<18];
int ans[18][1<<18];
int getdp(int lb, int dat)
{
    if(lb == -1) return x[dat];
    int& ret = dp[lb][dat];
    if(~ret) return ret;
    if((1 << lb) & dat)
    {
        ret = std::max(getdp(lb-1, dat), getdp(lb-1, dat-(1<<lb)));
    }
    else
    {
        ret = getdp(lb-1, dat);
    }
    return ret;
}
int chk(int lb, int dat)
{
    if(lb == -1) return 0;
    int& ret = ans[lb][dat];
    if(~ret) return ret;
    ret = 0;
    if((1 << lb) & dat)
    {
        ret = std::max(chk(lb-1, dat), getdp(lb-1, dat)+getdp(lb-1, dat-(1<<lb)));
    }
    else
    {
        ret = chk(lb-1, dat);
    }
    return ret;
}
int main()
{
    scanf("%d", &n);
    for(int i=0;i<(1<<n);i++)
    {
        scanf("%d", &x[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            ans[i][j] = dp[i][j] = -1;
        }
    }
    int prev = 0;
    for(int i=1;i<(1<<n);i++)
    {
        prev = std::max(prev, chk(n-1, i));
        printf("%d\n", prev);
    }
}