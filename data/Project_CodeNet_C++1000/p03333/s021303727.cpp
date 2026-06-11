#include<bits/stdc++.h>
using namespace std;
int n,l[100005],r[100005];
long long ans;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
	n=read();
	for(int i=0;i<n;++i) l[i]=read(),r[i]=read();
	sort(l,l+n+1); sort(r,r+n+1);
	for(int i=0;i<n;++i){
		if(l[n-i]-r[i]<1) break;
		ans+=l[n-i]-r[i];
	}
	printf("%lld",ans<<1);
}