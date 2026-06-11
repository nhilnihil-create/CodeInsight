#include<bits/stdc++.h>
using namespace std;
int n,k,q,a[10005],b[10005],ans=1e9;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
bool check(int l,int r){
	int p=0,j,t,s=0;
	for(int i=1;i<=n+1;++i)
		if(a[i]<b[l]){
			for(t=0,j=p;++j<i;)if(a[j]<=b[r])++t;
			s+=max(0,min(t,i-p-k));p=i;
		}
	return s>=q;
}
int main(){
	n=read(),k=read(),q=read();
	for(int i=1;i<=n;++i)a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1,j=1;i<=n;++i){
		while(j<=n&&!check(i,j))++j;
		if(j<=n)ans=min(ans,b[j]-b[i]);
	}
	printf("%d",ans);
}