#include <iostream>
#include <fstream>
using namespace std;
const int nmax=100005;
int aib[2*nmax];
int a[nmax];
int n,i,j,zr;
inline int lbit(int x)
{
    return (((x^(x-1))&x));
}
void update(int poz,int val)
{
    for(int idx=poz;idx<=2*n+1;idx+=lbit(idx))
        aib[idx]+=val;
}
int compute(int poz)
{
    int ret=0;
    for(int idx=poz;idx>0;idx-=lbit(idx))
        ret+=aib[idx];
    return ret;
}
long long check(int val)
{
    long long ret=0,sum=0;
    update(zr,1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=val) sum++;
        if(a[i]>val) sum--;
        ret+=1LL*compute(sum+zr-1);
        update(sum+zr,1);
    }
    for(i=1;i<=2*n;i++)
        aib[i]=0;
    return ret;
}
int main()
{
    //freopen("data.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;zr=n+1;
    long long c=(1LL*n*(n+1)/2)/2+1;
    for(int p=30;p>=0;p--)
        if(check(ans+(1<<p))<c)
              ans+=(1<<p);
    ans++;
    cout<<ans;
    return 0;
}