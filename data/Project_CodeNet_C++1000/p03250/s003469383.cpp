#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,a[3];
	for(i=0;i<3;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+3);
	printf("%d\n",a[2]*10+a[1]+a[0]);
	return 0;
}
		