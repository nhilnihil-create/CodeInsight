#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=2000+10,inf=0x3f3f3f3f;
int a[maxn],num[maxn],tmp,num1[maxn],tmp1;
int main(){
	int n=read(),k=read(),q=read();
	REP(i,1,n) a[i]=read();
	int ans=inf;
	REP(_,1,n){
		tmp=0;
		for(int i=1,j;i<=n;i=j+1){
			j=i;
			if(a[i]>=a[_]){
				while(a[j+1]>=a[_]) ++j;
				if(j-i+1>=k){
					tmp1=0;
					REP(l,i,j) num1[++tmp1]=a[l];
					nth_element(num1+1,num1+j-i+2-k,num1+tmp1+1);
					REP(l,1,j-i+2-k) num[++tmp]=num1[l];
				}
			}
		}
		if(tmp>=q){
			nth_element(num+1,num+q,num+tmp+1);
			chkmin(ans,num[q]-a[_]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
