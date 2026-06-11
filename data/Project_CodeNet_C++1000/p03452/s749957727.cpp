#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
template<class _Tp>_Tp max(_Tp a,_Tp b){if(a>b) return a;return b;}
template<class _Tp>_Tp min(_Tp a,_Tp b){if(a<b) return a;return b;}
template<class _Tp>void ckmax(_Tp &a,_Tp b){if(a<b) a=b;}
template<class _Tp>void ckmin(_Tp &a,_Tp b){if(a>b) a=b;}
template<class _Tp>void sswap(_Tp &a,_Tp &b){_Tp c=a;a=b;b=c;}
template<class _Tp>_Tp gcd(_Tp a,_Tp b){return (b==0)?(a):(gcd(b,a%b));}
template<class _Tp>_Tp abs(_Tp a){if(a<0)return-a;return a;}
int read(){
	char ch=getchar();bool f=1;int x=0;
	while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if(ch=='-') f=0,ch=getchar();
	while(ch>='0' && ch<='9'){x=x*10+(ch&15);ch=getchar();}
	return f?x:-x;
}
ll readll(){
	char ch=getchar();bool f=1;ll x=0ll;
	while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if(ch=='-') f=0,ch=getchar();
	while(ch>='0' && ch<='9'){x=x*10+(ch&15ll);ch=getchar();}
	return f?x:-x;
}
const int inf=1000000000;
#define N 200050
int n,m,fa[N],dis[N];
bool flag=1;
int get(int x){
	if(fa[x]!=x){
		int nowf=fa[x];
		fa[x]=get(fa[x]);
		dis[x]+=dis[nowf];
	}
	return fa[x];
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1;i<=m;++i){
		int l=read(),r=read(),d=read();
		int fl=get(l),fr=get(r);
		if(fl==fr&&dis[l]-dis[r]!=d)flag=0;
		if(fl!=fr){
			fa[fl]=fr;
			dis[fl]=d+dis[r]-dis[l];
		}
	}
	if(flag)puts("Yes");
	else puts("No");
	return 0;
}
