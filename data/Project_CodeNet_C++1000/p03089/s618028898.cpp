#include<cstdio>

using namespace std;

int a[101];
int b[101];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i;i--){
		int o=0;
		for(int j=1;j<=i;j++)
			if(a[j]==j)o=j;
		if(o==0){
			printf("-1\n");
			return 0;
		}
		b[++b[0]]=o;
		for(int j=o;j<i;j++)
			a[j]=a[j+1];
	}
	for(int i=b[0];i;i--)
		printf("%d\n",b[i]);
}