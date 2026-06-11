#include<cstdio>
#include<algorithm>
using namespace std;

int p[5001];
int f1[5001][5002],f2[5001][5002];
long long f[5002];
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n+1;j++){
			f1[i][j]=f1[i][j-1]+(i!=0&&j!=n+1&&p[j]<p[i]);
			//printf("1:%d %d %d\n",i,j,f1[i][j]);
		}
	for(int j=1;j<=n+1;j++)
		for(int i=j-1;i>=0;i--){
			f2[i][j]=f2[i+1][j]+(i!=0&&j!=n+1&&p[j]<p[i]);
			//printf("2:%d %d %d\n",i,j,f2[i][j]);
		}
	for(int i=1;i<=n+1;i++)
		f[i]=~0ull>>1;
	for(int i=0;i<=n+1;i++){
		//printf("%d %lld\n",i,f[i]);
		for(int j=i+1;j<=n+1;j++)
			if(!(i==0&&j==n+1)&&(i==0||j==n+1||p[j]>p[i])&&f1[i][j]+f2[i][j]==j-i-1){
				f[j]=min(f[j],f[i]+1ll*f1[i][j]*b+1ll*f2[i][j]*a);
				//printf("%d %d %lld\n",i,j,f[i]+1ll*f1[i][j]*b+1ll*f2[i][j]*a);
			}
	}
	printf("%lld\n",f[n+1]);
}