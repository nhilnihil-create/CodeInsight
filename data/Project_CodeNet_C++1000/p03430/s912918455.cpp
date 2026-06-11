#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",x)
#define pp(x,y)     printf("~~%lld %lld~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",a,b,c,d)
#define f_in(x)     freopen(x,"r",stdin)
#define f_out(x)    freopen(x,"w",stdout)
#define open(x)     f_in(x".in"),f_out(x".out")
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#define NEG 1
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=getchar();   for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=getchar())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=getchar();   for (;!isdigit(ch);ch=getchar());    for (;isdigit(ch);ch=getchar())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=getchar();   for(;isspace(ch);ch=getchar());  return ch;  }
    inline ll readstr(char *s){ char ch=getchar();   int cur=0;  for(;isspace(ch);ch=getchar());      for(;!isspace(ch);ch=getchar())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
    inline ld getreal(){    static ld lbc;  scanf("%lf",&lbc);  return lbc; }
}using namespace SHENZHEBEI;
char s[310];ll f[310][310][310],n,m;
int main(){
	n=readstr(s+1),m=read();
	memset(f,60,sizeof f);
	For(i,0,n+1){
		memset(f[i][i],0,sizeof f[i][i]);
		if (i)memset(f[i][i-1],0,sizeof f[i][i-1]);
	}
	For(len,2,n){
		For(i,1,n){
            ll j=i+len-1;
            if (j>n)break;
            For(k,0,m){
                if (k)	f[i][j][k]=f[i+1][j-1][k-1];
                if (s[i]==s[j])Min(f[i][j][k],f[i+1][j-1][k]);
                Min(f[i][j][k],f[i+1][j][k]+1);
                Min(f[i][j][k],f[i][j-1][k]+1);
            }
        }
    }
    writeln(n-f[1][n][m]);
}