#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define LL long long
#define N 200010
#define INFINITY 0x3f3f3f3f
#define maxn 10005
#define mase(a,b) memset(a,b,sizeof(a))
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
using namespace std;
int a[N];
int main()
{
    int n;
    LL re;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(a[0]!=0)
    {
        printf("-1\n");
    }
    else
    {
        bool flag=true;
        re=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]-a[i-1]>1)
            {
                printf("-1\n");
                flag=false;
                break;
            }
            if(a[i]-a[i-1]==1)
            {
                re+=1;
            }
            else
            {
                re+=a[i];
            }
        }
        if(flag)
        {
            printf("%lld\n",re);
        }

    }
    return 0;
}
