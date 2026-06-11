#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,x[N],y[N],len,f[N],d[N];
void Print(int X,int Y){
	for (int i=1;i<=len;i++){
		if (abs(X)>abs(Y)){
			if (X>0) putchar('R'),X-=d[i];
			else putchar('L'),X+=d[i];
		}
		else {
			if (Y>0) putchar('U'),Y-=d[i];
			else putchar('D'),Y+=d[i];
		}
	}
	puts("");
	return;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		f[(x[i]+y[i])%2]++;
	}
	if (f[1]&&f[0]){
		puts("-1");
		return 0;
	}
	for (int i=30;i>=0;i--)d[++len]=(1<<i);
	if (f[0])d[++len]=1;
	printf("%d\n",len);
	for (int i=1;i<=len;i++)printf("%d ",d[i]);
	puts("");
	for (int i=1;i<=n;i++)Print(x[i],y[i]);
}
