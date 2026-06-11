#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef double db;
#define ls(x) x<<1
#define rs(x) x<<1|1
#define low(x) (x&-x)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define X first
#define Y second
#ifdef _DEBUG
    const int N=1e3+10;
#else
    const int N=1e6+10;
#endif
const ll mod=1e9+7;
template<typename T> inline T gcd(T a,T b){return !b?a:gcd(b,a%b);}
template<typename T> inline T q_pow(T a,T x){T ans=1,tmp=a;while(x){if(x&1)(ans*=tmp)%=mod;(tmp*=tmp)%=mod;x>>=1;}return ans;}
template<typename T> inline void re(T &N){int f=1;char c;while((c=getchar())< '0'||c> '9')if(c=='-')f=-1;N=c-'0';while((c=getchar())>='0'&&c<='9')N=N*10+c-'0';N*=f;}
int m,n,t=1,st,en;
int a[N],b[N],d[N];
char s[N];

int main()
{
    // freopen("data.txt","r",stdin);
    re(n);
    for(int i=1;i<=n;i++)re(a[i]);
    int l=0,r=0;ll ans=0;
    while(r< n)
    {
        r++;int ma=-1;
        for(int i=0;i<=20;i++)if((a[r]>>i)&1)
        {
            if(d[i])ma=max(ma,d[i]);
            d[i]=r;
        }
        if(ma>=0)l=max(l,ma);
        ans+=r-l;
    }
    printf("%lld\n",ans);
}
