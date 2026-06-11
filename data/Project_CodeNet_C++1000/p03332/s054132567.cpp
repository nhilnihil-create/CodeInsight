/*
ID: jerrywcy
LINK: https://atcoder.jp/contests/agc025/tasks/agc025_b
LANG: C++
STATUS:
*/
#include <bits/stdc++.h>

#define init(array,x) memset(array,x,sizeof(array))

using namespace std;

typedef long long ll;

const ll inf=0x3f3f3f3f;
const ll mod=998244353;

ll n,a,b,k;
ll f[3000010],g[3000010];
ll ans;

ll read(){
    ll f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

ll pow(ll x,ll y){
    ll ret=1;
    while (y){
        if (y&1)ret=(ret*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ret;
}

void getf(){
    f[1]=1;
    for (int i=2;i<=n;i++)f[i]=(f[i-1]*i)%mod;
    g[n]=pow(f[n],mod-2);
    for (int i=n-1;i>=1;i--)g[i]=(g[i+1]*(i+1))%mod;
    return ;
}

ll C(int x,int y){
    if (x<y)return 0;
    if (y==0 || y==x)return 1;
    return ((((f[x]*g[y])%mod)*g[x-y])%mod);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    n=read();a=read();b=read();k=read();
    getf();
    for (int i=0;i*a<=k;i++){
        if ((k-i*a)%b==0){
            int j=(k-i*a)/b;
            ans=(ans+(C(n,i)*C(n,j))%mod)%mod;
        }
    }
    printf("%lld\n",ans);

	return 0;
}
