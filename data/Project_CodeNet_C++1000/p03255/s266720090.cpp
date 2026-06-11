#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const double eps=1e-9;
int read(){
	int f=1,g=0;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
int n;
ll m,a[N],ans;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)a[i]+=a[i-1];
	ans=1000000000000000000;
	for (int i=1;i<=n;i++){
		ll t=n*m+i*m+a[n]*5;bool fl=0;
		for (int j=n-i*2;j>0;j-=i){
			t+=a[j]*2;
			if (t<0) fl=1;
		}
		if (!fl) ans=min(ans,t);
	}
	printf("%lld\n",ans);
	return 0;
}