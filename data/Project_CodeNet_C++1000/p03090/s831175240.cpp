#include<cstdio>

using namespace std;

int ansu[100001],ansv[100001],ans;
int main(){
	int n;
	scanf("%d",&n);
	if(n&1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++)
				if(j!=i&&j!=n-i){
					ansu[++ans]=i;
					ansv[ans]=j;
				}
		}
	}
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				if(j!=i&&j!=n-i+1){
					ansu[++ans]=i;
					ansv[ans]=j;
				}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		printf("%d %d\n",ansu[i],ansv[i]);
}