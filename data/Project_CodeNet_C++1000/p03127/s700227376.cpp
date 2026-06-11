#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    long long int n,i,x,ans;
    scanf("%lld",&n);
    vector<long long int>v;
    for(i=0;i<n;i++)
    {
        long long int p;
        scanf("%lld",&p);
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    ans=v[0];
    for(i=1;i<n;i++)
    {
        x=__gcd(ans,v[i]);
        ans=min(x,v[i]);
    }
    printf("%lld",ans);

    return 0;


}

