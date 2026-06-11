#include <cstdio>

inline int read(){
	char c=getchar(); int x=0,ft=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') ft=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*ft;
}

const int N=2e5+5;

int n,a[N],s[N],c[N],top;

void insert(int x){
	if(s[top]<x) s[++top]=x,c[top]=1; else ++c[top];
}

bool check(int k){
	top=0;
	for(int i=2;i<=n;++i) if(a[i-1]>=a[i]){
		while(top&&s[top]>a[i]) --top; insert(a[i]);
		while(top&&c[top]==k){
			int pos=s[top--]; if(pos==1) return 0; insert(pos-1);
		}
	}
	return 1;
}

int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid; else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}