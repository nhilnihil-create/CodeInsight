#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x[1100],y[1100],d[1100];
bool v[1100];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		v[(x[i]+y[i])&1]=1;
	}
	if (v[0]&&v[1]){
		puts("-1");
		return 0;
	}
	if (v[0]) d[++m]=1;
	for (int i=30;i>=0;i--) d[++m]=1<<i;
	printf("%d\n",m);
	for (int i=1;i<m;i++) printf("%d ",d[i]);
	printf("%d\n",d[m]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (abs(x[i])>abs(y[i])){
				if (x[i]>0) x[i]-=d[j],putchar('R');
				else x[i]+=d[j],putchar('L');
			} else {
				if (y[i]>0) y[i]-=d[j],putchar('U');
				else y[i]+=d[j],putchar('D');
			}
		}
		putchar('\n');
	}
	return 0;
}
