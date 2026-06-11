#include<cstdio>
#define LL long long
using namespace std;
const int maxn=200005;
int n,a[maxn];
LL sum1[maxn],sum2[maxn],ans;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-f;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum1[i]=sum1[i-1]+a[i],sum2[i]=sum2[i-1]^a[i];
	int j=1;
	for (int i=1;i<=n;i++){
		ans+=(LL)j-i;
		while (j<=n&&sum1[j]-sum1[i-1]==(sum2[j]^sum2[i-1])) j++,ans++;
	}
	printf("%lld\n",ans);
	return 0;
}