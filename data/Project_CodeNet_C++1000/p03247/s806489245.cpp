#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,x[N],y[N],ans[N];
bool num[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		num[(x[i]+y[i])&1]=1;
	}
	if(num[0]&&num[1]){
		puts("-1");
		return 0;
	}
	if(num[0])ans[++m]=1;
	for(int i=30;i>=0;i--)ans[++m]=(1<<i);
	printf("%d\n",m);
	for(int i=1;i<m;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[m]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(abs(x[i])>abs(y[i])){
				if(x[i]>0)x[i]-=ans[j],putchar('R');
				else x[i]+=ans[j],putchar('L');
			}
			else{
				if(y[i]>0)y[i]-=ans[j],putchar('U');
				else y[i]+=ans[j],putchar('D');
			}
		}
		putchar('\n');
	}
	return 0;
}