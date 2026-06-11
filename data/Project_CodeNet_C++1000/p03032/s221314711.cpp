#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n,k,maxn=-9999999;
    scanf("%d%d",&n,&k);
    int num[55];
    for(int i=0; i<n; i++)
        scanf("%d",&num[i]);
    int a,b,c;
    for(a=0; a<=k; a++)
    {
        for(b=0; b<=k; b++)
        {
            for(c=0; c<=k; c++)
            {
                if(a+b+c<=k&&a+b<=n&&a+b>=c)
                {
                    priority_queue<int>q;
                    for(int i=0; i<a; i++)
                        q.push(num[i]);
                    for(int i=0; i<b; i++)
                        q.push(num[n-1-i]);
                    int sum=0;
                    for(int i=0;i<a+b-c;i++)
                    {
                        sum=sum+q.top();
                        q.pop();
                    }
                     maxn=max(maxn,sum);
                }

            }
        }
    }
    printf("%d",maxn);
    return 0;
}
