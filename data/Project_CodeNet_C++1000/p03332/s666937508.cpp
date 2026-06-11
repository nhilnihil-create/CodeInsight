#include<iostream>
#include<fstream>
#include<unordered_map>
#include<cmath>
using namespace std;
const int DN=3e5+5,M=998244353;
long long n,a,b,k,f,fact[DN],cnt,rez;
long long ve(long long a,long long b)
{
    long long p=1,r=1,c=a;
    while(p<=b)
    {
        if(p&b)
            r=(1LL*r*c)%M;
        c=(1LL*c*c)%M;
        p=p*2;
    }
    return r;
}
long long comb(long long n,long long k)
{
    long long r=(fact[n]*ve(fact[k],M-2))%M;
    r=(r*ve(fact[n-k],M-2))%M;
    return r;
}
int main()
{
    cin>>n>>a>>b>>k;
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=(1LL*fact[i-1]*i)%M;
    for(long long i=0;i<=n;i++)
    {
        f=k-i*a;
        if(f%b)
            continue;
        cnt=f/b;
        if(cnt<0||cnt>n)
            continue;
        rez=(rez+comb(n,i)*comb(n,cnt))%M;
    }
    cout<<rez;
}
