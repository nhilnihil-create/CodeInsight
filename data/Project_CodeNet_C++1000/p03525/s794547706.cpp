#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d[101],ans;

int main()
{
    scanf("%d",&n);
    n+=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&d[i]);
    }
    sort(d,d+n);
    for(int i=1;i<n;i++)
    {
        if(i%2) d[i] = 24-d[i];
    }
    sort(d,d+n);
    ans = 24-d[n-1];
    for(int i=1;i<n;i++)
    {
        //printf("%d %d\n",d[i],d[i-1]);
        ans = min(d[i]-d[i-1],ans);
    }
    
    printf("%d\n",ans);
    return 0;
}
