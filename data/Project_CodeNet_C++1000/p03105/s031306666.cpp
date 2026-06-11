#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <deque>
#include <stack>
#define ll long long
using namespace std;
int t,n,m;
int a,b,c;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        int x=floor(b/a);
        int ans=0;
        if(x>c) ans=c;
        else ans=x;
        printf("%d\n",ans);
    }

    return 0;
}
