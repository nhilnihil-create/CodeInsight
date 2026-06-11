#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=4e2+5;
int arr[N],n;
ll memo[N][N],pre[N];
ll dp(int i,int j)
{
    //printf("%d %d\n",i,j);

    if(i==j)
        return 0;


    ll &ret=memo[i][j];
    if(~ret)
        return ret;
    ret=1e17;
    for(int k=i;k<j;++k)
    {
        ret=min(ret,dp(i,k)+dp(k+1,j)+pre[j]-pre[i-1]);

    }

    return ret;

}
int main()
{
    memset(memo,-1 ,sizeof memo);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int a;
        scanf("%d",&a);
        pre[i]=pre[i-1]+a;
    }
    ll sol=dp(1,n);
    printf("%lld\n",sol);


    return 0;
}
