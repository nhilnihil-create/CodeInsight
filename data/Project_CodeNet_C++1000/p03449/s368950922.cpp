#include <stdio.h>
#include <stack>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int mp[3][105];
    scanf("%d",&n);
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=n;j++)
        scanf("%d",&mp[i][j]);
    }
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=n;j++)
            mp[i][j]+=max(mp[i][j-1],mp[i-1][j]);
    }
    printf("%d\n",mp[2][n]);
    return 0;
}