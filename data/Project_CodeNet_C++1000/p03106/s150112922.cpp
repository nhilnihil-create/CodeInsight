#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int a,b,k,x[100]={0},i,j,c=0;
	scanf("%d%d%d",&a,&b,&k);
	if(a>b){
		swap(a,b);
	}
	for(i=a;i>=1;i--){
		if(a%i==0&&b%i==0){
			c++;
			x[c]=i;
		}
	}
	printf("%d\n",x[k]);
	return 0;
}
