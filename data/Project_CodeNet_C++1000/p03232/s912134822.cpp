#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <algorithm>
#include <queue>
#include <deque>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include<sstream>
#define ll long long
#define maxn 101000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;

long long n,a[100100],ni[100100],sum[100100],ans,vk;
int main()
{
    #ifdef local
    freopen("in.txt", "r", stdin);
    #endif // local
	scanf("%lld",&n);
	vk=1;
	for(ll i=1;i<=n;i++)
        vk=vk*i%mod;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    ni[0]=ni[1]=1;
    sum[1]=1;
    for(ll i=2;i<=n;i++)
    {
        ni[i]=(mod-mod/i)*ni[mod%i]%mod;
        sum[i]=(sum[i-1]+ni[i])%mod;
    }
    //for(int i=1;i<=n;i++)printf("%lld    %lld\n",ni[i],sum[i]);
    for(int i=1;i<=n;i++)
    {
        ans=(ans+sum[n-i+1]*a[i]%mod+(sum[i]-1)*a[i]%mod)%mod;
    }
    ans=(ans*vk)%mod;
    printf("%lld",ans);
	return 0;
}







