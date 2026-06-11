#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const int maxn=1e2+5;
const int maxk=1e5+5;
int a[maxn];
ll num[maxk],front[maxk];
void update(int k)
{
    front[0]=num[0];
    for(int i=1;i<=k;i++)
        front[i]=(front[i-1]+num[i]-(front[i-1]+num[i]>=mod)*mod);
    return;
}
ll query(int l,int r)
{
    if(l==-1) return front[r];
    else return (front[r]-front[l]+(front[r]-front[l]<0)*mod);
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    num[0]=1;
    update(k);
    for(int i=1;i<=n;i++)
    {
        memset(num,0,sizeof(num));
        for(int j=0;j<=k;j++)
            num[j]=query(max(0,j-a[i])-1,j);
        update(k);
    }
    printf("%lld\n",num[k]);
    return 0;
}
