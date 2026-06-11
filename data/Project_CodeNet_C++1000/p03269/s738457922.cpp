#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
const int maxn=1e5+7;
const ll modn=1e9+7;
const int inf=2e9+7;
const double PI = acos(-1.0);
const double eps=1e-8;
inline int lowbit(int x){return x&-x;}
inline ll lowbit(ll x) {return x&-x;}
inline int CountOneBinary(ll num){int ans=0;while(num){if(num&1) ans+=1;num>>=1;}return ans;}
inline void read(int &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline void read(ll &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline ll qpow(ll x,ll y){ll ans=1;while(y){if(y&1) ans=ans*x%modn;x=x*x%modn;y>>=1;}return ans;}
inline double qpow(double x,ll y){double ans=1;while(y){if(y&1) ans=ans*x;x=x*x;y>>=1;}return ans;}
ll n,m;
ll u[maxn],v[maxn],w[maxn];
int main()
{
    ll l;
    while(scanf("%lld",&l)==1)
    {
        for(n=0,m=0;(1ll<<n)<=l;n++);
        for(int i=1;i<n;i++)
        {
            u[m]=i;v[m]=i+1;w[m]=0;m++;
            u[m]=i;v[m]=i+1;w[m]=1ll<<(i-1);m++;
        }
        ll tn=l-(1ll<<(n-1)),cur=1ll<<(n-1);
        for(ll i=n-1;i;i--)
        {
            int curn=1ll<<(i-1);
            if(tn>=curn)
            {
                u[m]=i;v[m]=n;w[m]=cur;cur+=curn;m++;
                tn-=curn;
            }
        }
        printf("%lld %lld\n",n,m);
        for(int i=0;i<m;i++) printf("%lld %lld %lld\n",u[i],v[i],w[i]);
    }
}
