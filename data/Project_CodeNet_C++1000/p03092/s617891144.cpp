#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int read(){
	int f=1,g=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
int n,A,B,pos[N];
ll f[N],ans;
int main(){
	n=read();A=read();B=read();
	for (int i=1;i<=n;i++) pos[read()]=i-1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) f[j]=min(f[j],f[j-1]);
		for (int j=0;j<=n;j++) f[j]+=(pos[i]==j) ? 0 : ((pos[i]<j) ? A : B);
	}
	ans=inf;
	for (int i=0;i<=n;i++) ans=min(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}