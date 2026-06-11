#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,m,mn;
    cin>>m;
    n=5;
    mn=1e15;
    while(n--)
    {
        cin>>x;
        mn=min(mn,x);
    }
    x=ceil((m*1.0)/mn);
    x=x+4;
    printf("%lld\n",x);
    return 0;
}
