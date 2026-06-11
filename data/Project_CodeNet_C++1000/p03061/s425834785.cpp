#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int main[n],left[n+1],right[n+2];
    for(int i=0; i<n; i++)
        scanf("%d", &main[i]);
    left[0]=0,right[n+1]=0;
    for(int i=1; i<=n; i++)
    {
        left[i]=__gcd(left[i-1],main[i-1]);
        right[n+1-i]=__gcd(right[n+2-i],main[n-i]);
    }

    int ans=1;
    for(int i=1; i<=n; i++)
        ans=max(__gcd(left[i-1],right[i+1]),ans);
    //ans=max(ans,right[1]);
    printf("%d\n", ans);
    return 0;
}