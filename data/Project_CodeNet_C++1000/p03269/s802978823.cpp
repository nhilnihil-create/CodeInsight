#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iostream> 
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#define ll long long
#define ull unsigned long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define lowbit(x) (x& -x)
#define mod 1000000007
#define inf 0x3f3f3f3f
#define eps 1e-18
#define maxn 100010
inline ll read(){ll tmp=0; char c=getchar(),f=1; for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1; for(;'0'<=c&&c<='9';c=getchar())tmp=(tmp<<3)+(tmp<<1)+c-'0'; return tmp*f;}
inline ll power(ll a,ll b){ll ans=1; for(;b;b>>=1){if(b&1)ans=ans*a%mod; a=a*a%mod;} return ans;}
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline void swap(int &a,int &b){int tmp=a; a=b; b=tmp;}
using namespace std;
int x[110],y[110],d[110];
int a[30],base[30];
int n,m,l;
int main()
{
    l=read();
    if(l<=2){//特判是因为若l<=2，下面建图是时图只有一个点，无法连边
        printf("2 %d\n",l);
        for(int i=0;i<l;i++)
            printf("1 2 %d\n",i);
        return 0;
    }
    int len=0;
    while(1<<len<=l)++len;
    n=len; m=0;
    for(int i=0;i<len-1;i++){//二进制拆分
        x[++m]=i+1; y[m]=i+2; d[m]=0;
        x[++m]=i+1; y[m]=i+2; d[m]=1<<i;
    }
    for(int i=len-2;i>=0;i--)
        if(l&(1<<i)){//其实和数位dp一样啦
            x[++m]=i+1; y[m]=n; d[m]=l>>(i+1)<<(i+1);
        }
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++)
        printf("%d %d %d\n",x[i],y[i],d[i]);
    return 0;
}