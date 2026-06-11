#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int v[55];
    int ans=-9999999;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    int a,b,c;
    for(a=0; a<=k; a++)
    {
        for(b=0; b<=k; b++)
        {
            for(c=0; c<=k; c++)
            {
                if(a+b+c<=k&&a+b>=c&&a+b<=n)
                {
                    priority_queue<int>q;
                    for(int i=0; i<a; i++)
                    {
                        q.push(v[i]);
                    }
                    for(int i=0; i<b; i++)
                    {
                        q.push(v[n-i-1]);
                    }
                    int sum=0;
                    for(int i=0; i<a+b-c; i++)
                    {
                        sum+=q.top();
                        q.pop();
                    }
                    ans=max(ans,sum);
                }

            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
