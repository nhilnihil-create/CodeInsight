#include <iostream>
#include <fstream>
using namespace std;
const long long mod=1000*1000*1000+7;
const int nmax=100005;
long long fact[nmax],a[nmax],s[nmax];
long long ans,ad;
int n,i;
long long expo(long long A,int B)
{
    long long ret=1,p2=A;
    for(int p=0;p<=30;p++)
    {
        if(((1<<p)&B))
        ret=(1LL*ret*p2)%mod;
       p2=(1LL*p2*p2)%mod;
    }
    return ret;
}
int main()
{
    //freopen("data.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n;
    fact[0]=1;
    for(i=1;i<=n;i++)
        fact[i]=(1LL*fact[i-1]*i)%mod;
    for(i=2;i<=n;i++)
        s[i]=(s[i-1]+1LL*expo(i,mod-2))%mod;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        ans=(ans+1LL*s[i]*a[i])%mod;
        ans=(ans+1LL*s[n-i+1]*a[i])%mod;
        ans=(ans+a[i])%mod;
    }
    cout<<(ans*fact[n])%mod;
    return 0;
}
