#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define max(x,y) ((x)>(y)?(x):(y))
int n,x,y,ans,a[N];
int main()
{
    scanf("%d %d %d",&n,&x,&y);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    if(n==1) printf("%d\n",abs(a[n]-y));else printf("%d\n",max(abs(a[n]-y),abs(a[n]-a[n-1])));
}