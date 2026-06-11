//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
inline char getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
int read(){
    R int res,f=1;R char ch;
    while((ch=getc())>'9'||ch<'0')(ch=='-')&&(f=-1);
    for(res=ch-'0';(ch=getc())>='0'&&ch<='9';res=res*10+ch-'0');
    return res*f;
}
int read(char *s){
	R int len=0;R char ch;while(((ch=getc())>'Z'||ch<'A'));
	for(s[++len]=ch;(ch=getc())>='A'&&ch<='Z';s[++len]=ch);
	return s[len+1]='\0',len;
}
inline char getop(){R char ch;while((ch=getc())>'Z'||ch<'A');return ch;}
const int N=2e5+5;
struct node{char c,d;}q[N];char s[N];
int n,m,l,r,mid,ansl,ansr;
bool ck(int pos){
	int x=mid;
	fp(i,1,m)if(s[x]==q[i].c){
		q[i].d=='L'?--x:++x;
		if(x<1||x>n)return x==pos;
	}
	return false;
}
int main(){
//	freopen("testdata.in","r",stdin);
	n=read(),m=read(),read(s);
	fp(i,1,m)q[i].c=getop(),q[i].d=getop();
	l=1,r=n,ansl=0;
	while(l<=r){
		mid=(l+r)>>1;
		ck(0)?(ansl=mid,l=mid+1):r=mid-1;
	}
	l=1,r=n,ansr=n+1;
	while(l<=r){
		mid=(l+r)>>1;
		ck(n+1)?(ansr=mid,r=mid-1):l=mid+1;
	}
	printf("%d\n",ansr-ansl-1);
	return 0;
}