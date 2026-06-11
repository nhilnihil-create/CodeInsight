#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10,mod=1e9+7,inf=0x3f3f3f3f;
int n,m,k,t;
ll facn=1,inv[maxn],a[maxn];
int main()
{
    int i,j;
  	//freopen("in.txt","r",stdin);
    scanf("%d",&n);
    inv[0]=inv[1]=1;
    for(i=1;i<=n;i++)
    {
        facn=facn*i%mod;
        if(i>=2)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        scanf("%lld",&a[i]);
    }
    for(i=2;i<=n;i++)(inv[i]+=inv[i-1])%=mod;
    ll ret=0;
    for(i=1;i<=n;i++)
    {
        ll tmp=inv[i]+inv[n-i+1]-inv[1];
        (ret+=tmp*a[i]%mod)%=mod;
    }
    (ret*=facn)%=mod;
    (ret+=mod)%=mod;
    printf("%lld\n",ret);
  	return 0;
}
