#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a=0,b=0,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(i%2==0) a++;
		else b++;
	}
	printf("%d\n",a*b);
	return 0;
}
