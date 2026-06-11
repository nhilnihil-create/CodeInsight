#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int a[10];
int nums[10]={0,2,5,5,4,5,6,3,7,6};

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d",&a[i]);

    int dp[10050]={};
    for(int i=0;i<=n;i++) dp[i]=-1;
    dp[0]=0;
    for(int i=0;i<=n;i++)
    {
        if(dp[i]==-1) continue;
        for(int j=0;j<m;j++)
        {
            if(dp[i]+1>dp[i+nums[a[j]]]) dp[i+nums[a[j]]]=dp[i]+1;
        }    
    }
    // printf("%d\n",dp[n]);
    for(int i=0;i<m;i++) a[i]=-a[i];
    sort(a,a+m);
    for(int i=0;i<m;i++) a[i]=-a[i];

    for(int i=n;i>0;)
    {
        for(int j=0;j<m;j++)
        {
            if(i-nums[a[j]]<0)continue; 
            if(dp[i]==dp[i-nums[a[j]]]+1)
            {
                printf("%d",a[j]);
                i-=nums[a[j]];
                // fflush(stdout);
                break;
            }
        }
    }
    printf("\n");
}