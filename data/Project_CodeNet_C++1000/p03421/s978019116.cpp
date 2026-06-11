#include <bits/stdc++.h>
int n,a,b,p[300005];
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if (n<a+b-1 || n>1ll*a*b){
		puts("-1");
		return 0;
	}
	int cnt=0,now=1;
	for (int i=n-a+1;i<=n;i++){
		p[++cnt]=i;
		int x=std::min(now+b-2,n-a);
		for (int j=1;now<=n-a && j<b;j++,now++)
			p[++cnt]=x--;
	}
	for (int i=1;i<=n;i++) printf("%d ",p[i]);
}