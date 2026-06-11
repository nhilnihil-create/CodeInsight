#include<iostream>
#include<bitset>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<set>
#include<deque>
#include<map>
#include<string>
#define mst(var,val) memset(var,val,sizeof(var))
#define IOS ios::sync_with_stdio(false);cin.tie(0)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+10;
const int seed=131;
const int N=1e5+10;
const int M=2e5+10;
const int mod=1e9+7;
const double eps=1e-6;

template <class T>
inline void read(T &x)
{
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar())
        f ^= c == '-';
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10)
        ++len;
    for (; len; --len, x %= y, y /= 10)
        putchar(x / y + 48);
}

int qpow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return (int) ret;
}


int inv[N];
int a[N];

int main(){
#ifdef local
    freopen("in.txt","r",stdin);
#endif // local
    IOS;

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) inv[i]=qpow(i,mod-2);
    for(int i=1;i<=n;i++) inv[i]=(inv[i]+inv[i-1])%mod;
    ll ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        ans=(ans+1ll*a[i]*inv[n-i+1]%mod)%mod;
        ans=(ans+1ll*a[i]*((inv[i]-inv[1]+mod)%mod)%mod)%mod;
    }
    for(int i=1;i<=n;i++) ans=ans*i%mod;
    printf("%lld\n",ans);
    return 0;
}
