#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,a,b;
void solve()
{
    if(a+b-1>n||(ll)a*b<n){printf("-1\n");return;}
    while(n>0)
    {
        int x=min(a,n-b+1);
        for(int i=n-x+1;i<=n;i++)
            printf("%d ",i);
        n-=x;
        b--;
    }
    printf("\n");
}
int main()
{
    while(scanf("%d%d%d",&n,&a,&b)!=EOF)
        solve();
}
