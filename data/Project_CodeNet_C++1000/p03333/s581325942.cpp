#include <stdio.h>
#include <string.h>
#include <algorithm>
#define R register
typedef long long i64;
namespace IO{
	char buf[1<<15],*S,*T;
	inline char gc(){
		if (S==T){
			T=(S=buf)+fread(buf,1,1<<15,stdin);
			if (S==T) return EOF;
		}return *S++;
	}
	inline int read(){
		R int x; R bool f; R char c;
		for (f=0; (c=gc())<'0'||c>'9'; f=c=='-');
		for (x=c^'0'; (c=gc())>='0'&&c<='9'; x=(x<<1)+(x<<3)+(c^'0'));
		return f?-x:x;
	}
}
#define MN 100005
int n,l[MN],r[MN],lrk[MN],rrk[MN],cnt,pos,ll,rr;bool vis[MN],op;i64 ans,ans2;
inline bool cmp1(int a,int b){return r[a]<r[b];}
inline bool cmp2(int a,int b){return l[a]>l[b];}
int main(){
	n=IO::read();for (R int i=1; i<=n; ++i)
		l[i]=IO::read(),r[i]=IO::read(),lrk[i]=rrk[i]=i;
	std::sort(lrk+1,lrk+n+1,cmp2);std::sort(rrk+1,rrk+n+1,cmp1);
	for (memset(vis,0,sizeof vis),cnt=op=pos=0,ll=1,rr=1; cnt<n; ++cnt,op^=1){
		if (op){
			while(vis[lrk[ll]]) ++ll;vis[lrk[ll]]=1;
			if (pos<l[lrk[ll]]) ans+=l[lrk[ll]]-pos,pos=l[lrk[ll]];
			else if (pos>r[lrk[ll]]) ans+=pos-r[lrk[ll]],pos=r[lrk[ll]];
		}else{
			while(vis[rrk[rr]]) ++rr;vis[rrk[rr]]=1;
			if (pos<l[rrk[rr]]) ans+=l[rrk[rr]]-pos,pos=l[rrk[rr]];
			else if (pos>r[rrk[rr]]) ans+=pos-r[rrk[rr]],pos=r[rrk[rr]];
		}
	}
	ans+=pos<0?-pos:pos;
	for (memset(vis,0,sizeof vis),op=1,cnt=pos=0,ll=1,rr=1; cnt<n; ++cnt,op^=1){
		if (op){
			while(vis[lrk[ll]]) ++ll;vis[lrk[ll]]=1;
			if (pos<l[lrk[ll]]) ans2+=l[lrk[ll]]-pos,pos=l[lrk[ll]];
			else if (pos>r[lrk[ll]]) ans2+=pos-r[lrk[ll]],pos=r[lrk[ll]];
		}else{
			while(vis[rrk[rr]]) ++rr;vis[rrk[rr]]=1;
			if (pos<l[rrk[rr]]) ans2+=l[rrk[rr]]-pos,pos=l[rrk[rr]];
			else if (pos>r[rrk[rr]]) ans2+=pos-r[rrk[rr]],pos=r[rrk[rr]];
		}
	}
	ans2+=pos<0?-pos:pos;
	ans=ans2>ans?ans2:ans;
	printf("%lld\n",ans);
}