#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
const int N = 100005;
using namespace std;
typedef long long ll;
int a[N];
int main()
{
 
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    ll imax=2,imin=2;
 
    for(int i=n;i>=1&&imax>=imin;i--){
        if(imin%a[i]!=0)
            imin=imin/a[i]*a[i]+a[i]; //最小 计算机乘除法处理求出a[i]的整数倍
        imax=(imax/a[i]+1)*a[i]-1;    //最大 
    }
    if(imax>imin)
        printf("%lld %lld\n",imin,imax);
    else
        printf("-1\n");
    return 0;
}