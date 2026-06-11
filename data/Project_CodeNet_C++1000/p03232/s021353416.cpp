#include<bits/stdc++.h>
#define up(j,k,i) for(i=j;i<k;i++)
#define down(j,k,i) for(i=j;i>k;i--)
#define ipp(n) printf("%d\n",n)
#define pp(n) printf("%lld\n",n)
#define pps(n) printf("%lld ",n)
#define ipps(n) printf("%d ",n)
#define all(x) x.begin(),x.end()
#define ps(s) printf("%s",s)
#define is(n) scanf("%lld",&n)
#define iis(n) scanf("%d",&n)
#define ips(n) scanf("%lld",n)
#define ss(s) scanf("%s",s)
#define cool 0
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define f(i) cout<<i<<endl;
#define pll pair<lld,lld> 
#define pi acos(-1)
#ifdef G
#define dg(x) cout<<#x<<' '<<x<<endl;
#define dg2(x,y) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define dg3(x,y,z) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define dg4(x,y,z,zz) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<' '<<#zz<<' '<<zz<<endl;
#else
#define dg(x) ;
#define dg2(x,y) ;
#define dg3(x,y,z) ;
#define dg4(x,y,z,zz) ;
#endif
#define ds(n,m) scanf("%lld %lld",&n,&m)
#define ids(n,m) scanf("%d %d",&n,&m)
#define ts(n,m,k) scanf("%lld %lld %lld",&n,&m,&k)
#define its(n,m,k) scanf("%d %d %d",&n,&m,&k)
#define yes printf("YES\n")
#define no printf("NO\n")
#define isset(num,i) ((num&(1LL<<i))!=0)
typedef long double ld;
typedef long long int lld;
using namespace std;
const lld M =2e5+10;
const lld mod=1e9+7;
const lld infi =LLONG_MAX;
lld ans,k,n,x,y,m,mymax=LLONG_MIN,mymin=LLONG_MAX,c,z,sum;
lld b[M],s[M];
lld binpow(lld base,lld pow,lld modulus)
{
    lld ans=1;
    base=base%modulus;
    while(pow>0)
    {   
        while(pow%2==0)
        {
            base=(base*base)%modulus;
            pow/=2;
        }
        ans=(ans*base)%modulus;
        pow--;
        
    }
    return ans;
}
lld fact(lld n)
{
    if(n<2)return 1;
    return (fact(n-1)*n)%mod;
}
int main()
{
    lld i,j;
    is(n);
    up(1,n+1,i){
    	is(b[i]);
    }
    s[1]=0;
    up(2,n+1,i){
        s[i]=(binpow(i,mod-2,mod)+s[i-1])%mod;
    }
    up(1,n+1,i){
        x=(s[i]+s[n-i+1])%mod;
        // x=(x-2+mod)%mod;
        x=(b[i]*x)%mod;
        ans=(ans+(x+b[i])%mod)%mod;
    }
    ans=(ans*fact(n))%mod;
    // ans=(ans+)
    pp(ans);
    return 0;
}