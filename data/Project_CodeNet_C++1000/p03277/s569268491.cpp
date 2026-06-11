#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#define ll long long
#define db double
#define rint register int
#define re register
#define eps 1e-10
#define mk make_pair
#define fs first
#define pint pair<int,int>
#define sd second
#define inf 1ll<<58
#define N 100005
using namespace std;
inline char get(){const int TOP=1<<20;static char T[TOP],*x=T,*y=T;return x==y&&(y=(x=T)+fread(T,1,TOP,stdin),x==y)?EOF:*x++;}
inline int read (){register int num,sign=1;register char c;
while (((c=get())<'0'||c>'9')&&c!='-');c=='-'?num=sign=0:num=c-48;while ((c=get())>='0'&&c<='9')num=(num<<3)+(num<<1)+(c-48);return sign?num:-num;}
int n,l,r,mid,ans=-1;
int s[N],A[N],tr[N*2];
inline void Mo(rint x){while(x<=2*n){tr[x]++;x+=x&-x;}}
inline int Qu(rint x){rint res=0;while(x){res+=tr[x];x-=x&-x;}return res;}
inline bool check(rint k){ll res=0;s[0]=0;
	memset(tr,0,sizeof(tr));
	for(rint i=1;i<=n;++i)s[i]=s[i-1]+(A[i]>=k?1:-1);
	for(rint i=0;i<=n;++i){res+=Qu(n+s[i]+1);Mo(n+s[i]+1);}
	return res>=1ll*n*(n+1)/4;
}
int main(){
	n=read();
	for(rint i=1;i<=n;++i)A[i]=read(),r=max(r,A[i]);
	while(l<=r){
		rint mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;else r=mid-1;
	}
	printf("%d\n",ans);
}
