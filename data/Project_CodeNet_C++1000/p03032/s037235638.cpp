#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#define maxn 105
#define inf 0x3f3f3f
using namespace std;


int main()
{
    int a,b,c;
    int f[55];
    int sum=0,ans=-inf;
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&f[i]);
    for(a=0;a<=k;a++)
        for(b=0;b<=k;b++)
            for(c=0;c<=k;c++)
    {

        priority_queue<int >q;
        if((a+b+c)<=k&&(a+b)>=c&&a+b<=n)
        {
            sum=0;
            for(int i=0;i<a;i++)
                q.push(f[i]);
            for(int i=0;i<b;i++)
                q.push(f[n-i-1]);
            for(int i=0;i<a+b-c;i++)
            {
                sum+=q.top();
                q.pop();
            }

            ans=max(sum,ans);

        }

    }
    cout<<ans<<endl;
    return 0;
}
