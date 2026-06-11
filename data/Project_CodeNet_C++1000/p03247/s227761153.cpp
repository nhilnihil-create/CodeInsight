#include <bits/stdc++.h>
using namespace std;
#define N 1010
int x[N],y[N],d[N];
bool flag[2];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}
signed main(){
	int n=read(),m=0;
	for (int i=1;i<=n;++i){
		x[i]=read(),y[i]=read();
		flag[(x[i]+y[i])&1]=1;
	}
	if (flag[0] && flag[1]){
		puts("-1");return 0;
	}
	if (flag[0]) d[++m]=1;
	for (int i=30;i>=0;--i) d[++m]=1<<i;
	cout<<m<<endl;
	for (int i=1;i<m;++i) printf("%d ",d[i]);
	printf("%d\n",d[m]);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			if (abs(x[i])>abs(y[i])){
				if (x[i]>0) x[i]-=d[j],putchar('R');
				else x[i]+=d[j],putchar('L');
			}else{
				if (y[i]>0) y[i]-=d[j],putchar('U');
				else y[i]+=d[j],putchar('D');
			}
		}
		putchar('\n');
	}
	return 0;
}
