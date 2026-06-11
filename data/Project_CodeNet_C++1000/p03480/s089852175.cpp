#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>
#include <memory>
#include <cstring>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#define LL long long
#define N 100005
#define maxn 100
#define INFINITY 0x3f3f3f3f
#define mase(a,b) memset(a,b,sizeof(a))
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define lson l,m,num<<1
#define rson m+1,r,num<<1|1
using namespace std;
char a[N];
int main()
{
    int re;
    int len;
    scanf("%s",a);
    len=strlen(a);
    re=len;
    for(int i=1;i<len;i++)
    {
        if(a[i]!=a[i-1])
        {
            re=MIN(re,MAX(i,len-i));
        }
    }
    printf("%d\n",re);
    return 0;
}
