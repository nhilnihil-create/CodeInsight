#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,b;
void solve()
{
    if(a+b>n+1||a*b<n)
    {
        printf("-1\n");
        return ;
    }
    while(n>0){
        ll x=min(a,n-b+1);
        for(ll i=n-x+1;i<=n;i++)
            printf("%d ",i);
        n-=x;
        b--;
    }
    printf("\n");
}
int main()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    solve();
}