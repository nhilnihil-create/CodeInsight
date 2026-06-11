#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
inline int read(){
	char ch=getchar(); int x=0;
	for (;ch>'9'||ch<'0';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}
int n,X,x[N],S[N],P[N];
signed main(){
	n=read(); X=read();
	for (int i=1;i<=n;i++) x[i]=read(),S[i]=S[i-1]+x[i];
	P[1]=5; for (int i=2;i<=n;i++) P[i]=2*i+1;
	int ans=9e18;
	for (int k=1;k<=n;k++){
		int tmp=0,p=n;
		for (int i=1;p>0;p-=k,i++){
			tmp+=(S[p]-S[max(p-k,0LL)])*P[i];
			if (tmp>ans) break;
		}
		tmp+=X*k;
		if (tmp<ans) ans=tmp;
	}
	printf("%lld\n",ans+n*X);
	return 0;			
}