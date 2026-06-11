#include<cstdio>

using namespace std;

const int md=1000000007;
int a[200001],f[200001],pre[200001];
int main(){
	int n;
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		f[i]=(f[i-1]+(pre[o]==i-1||pre[o]==0?0:f[pre[o]]))%md;
//		printf("%d %d %d\n",f[i],pre[o],f[i-1]+(pre[o]==i-1||pre[o]==0?0:f[pre[o]]));
		pre[o]=i;
	}
	printf("%d\n",f[n]);
}