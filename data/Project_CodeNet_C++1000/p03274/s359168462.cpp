#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
int n;
long long a[200500];
int main()
{
    ios::sync_with_stdio(false);
    int k,n,i;
    cin >> n >> k;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    long long ans=1e18+7;
    for (i=1;i+k-1<=n;i++)
    {
        long long tmp=a[i+k-1]-a[i];
        if ((a[i]<0) && (a[i+k-1]<0)) tmp+=abs(a[i+k-1]);
        if ((a[i]>0) && (a[i+k-1]>0)) tmp+=a[i];
        if ((a[i]<0) && (a[i+k-1]>0)) tmp+=min(-a[i],a[i+k-1]);
        ans=min(ans,tmp);
    }
    cout << ans;
    return 0;
}