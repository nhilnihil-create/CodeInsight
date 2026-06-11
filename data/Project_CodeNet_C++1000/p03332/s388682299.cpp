#include<cstdio>
#include<iostream>
#define maxn 3*100000+5
#define mod 998244353
using namespace std;
long long int a[maxn],in[maxn];
long long pow(long long x, long long n) {
    long long ret = mod!= 1;
    for (x %= mod; n; n >>= 1, x = x * x % mod)
        if (n & 1) ret = ret * x % mod;
    return ret;
}
 long long int mate( long long int m,  long long int n)
{
    if(m==0) return 1;
    if(n<m) return 0;
    if(n==m)  return 1;
        return a[n]*in[m]%mod*in[n-m]%mod;

}
int main()
{
    long long int sum=0,A,B,K,x,t,N,j,r,i;
    scanf("%lld%lld%lld%lld",&N,&A,&B,&K);
    a[0]=1;
    for(i=1;i<=N;i++)
        a[i]=(a[i-1]*i)%mod;
        in[N]=pow(a[N],mod-2);
        for(i=N-1;i>=0;i--)
            in[i]=in[i+1]*(i+1)%mod;
    if(K==0)
        {
            printf("1\n");
            return 0;
        }
    t=0;
    x=0;
    while(t<=N)
    {
        if((K-t*A)%B) {t++;continue;}
        x=(K-t*A)/B;
        if(x<=N&&t>=0&&x>=0)
        {
            sum=(sum+(mate(t,N)*mate(x,N))%mod)%mod;
        }
       t++;
    }
    printf("%lld\n",sum%mod);
}
