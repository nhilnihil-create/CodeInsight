#include <bits/stdc++.h>
#define mem(s,t) memset(s,t,sizeof(s))
#define pb(s) push_back(s)
#define inf 0x3f3f3f3f
#define mn 100010
typedef long long ll;
using namespace std;
double b[110],ans,sum;
int a[110];
int n,ansi;
int main()
{
    int i,j;
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    sum=0;
    for (i=0;i<n;i++)
        sum+=a[i];
    double k=sum*1.0/(n*1.0);
    for (i=0;i<n;i++)
        b[i]=fabs(a[i]-k);
    ans=b[0];
    ansi=0;
    for (i=1;i<n;i++)
    if (b[i]<ans)
    {
        ans=b[i];
        ansi=i;
    }
    printf("%d\n",ansi);
    return 0;
}