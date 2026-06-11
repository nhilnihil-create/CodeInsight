#include <iostream>
#include <fstream>
using namespace std;
const int nmax=100005;
int val[2*nmax],sum[2*nmax];
int a[nmax];
int n,i,j,zr;
void update(int poz,int value)
{
    val[poz]+=value;
    sum[poz]=sum[poz-1]+val[poz];
}
int compute(int poz)
{
    return sum[poz];
}
long long check(int value)
{
    long long ret=0;
    int summ=0;
    update(zr,1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=value) summ++;
        if(a[i]>value) summ--;
        ret+=1LL*compute(summ+zr-1);
        update(summ+zr,1);
    }
    for(i=1;i<=2*n+1;i++)
        val[i]=sum[i]=0;
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