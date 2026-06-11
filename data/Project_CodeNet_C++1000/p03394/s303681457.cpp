#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n==3) printf("2 5 63");
	else if(n<=15000) {
		if(n%3==1) {
			for(int i=1;i<=(n/3)*3-1;++i) printf("%d ",i*2);
			printf("%d %d",3,9);
		}
		else if(n%3==2) {
			for(int i=1;i<=(n/3)*3;++i) printf("%d ",i*2);
			printf("%d %d",3,9);
		}
		else {
			for(int i=1;i<=(n/3-1)*3;++i) printf("%d ",i*2);
			printf("%d %d %d",30000,3,9);
		}
	}
	else {
		if(n%2==0) {
			for(int i=1;i<=15000;++i) printf("%d ",i*2);
			for(int i=1;i<=n-15000;++i) printf("%d ",i*6-3);
		}
		else {
			for(int i=1;i<=14999;++i) printf("%d ",i*2);
			for(int i=1;i<=n-14999;++i) printf("%d ",i*6-3);
		}
	}
	return 0;
}