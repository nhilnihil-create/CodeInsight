/*#include<iostream>
#include<cstdio>
#include<algorithm>
*/
#include<bits/stdc++.h>
using namespace std;
#define max 200006

int main()
{
    int n,arr[max],i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int ans=__gcd(arr[0],arr[1]);
    for(i=2; i<n; ++i)
    {
        ans=__gcd(ans,arr[i]);
        if(ans==1)
            break;
    }
    printf("%d\n", ans);
    return 0;
}
