#define George_Plover
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define EPS (1e-9)
#define MAXN 300001
#define MOD 1000000007
#define ull unsigned long long
#define LL long long

using namespace std;
int n;
int color[MAXN];
int dp[MAXN];
int lst[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&color[i]);
    dp[0]=0;
    dp[1]=1;
    lst[color[1]]=1;
    for(int i=2;i<=n;i++)
    {
        if(color[i-1]==color[i])
            dp[i]=dp[i-1];
        else dp[i]=(dp[lst[color[i]]]+dp[i-1])%MOD;
        lst[color[i]]=i;
        //cout<<i<<" "<<dp[i]<<endl;
    }
    printf("%d\n",dp[n]);
    
    return 0;
}


