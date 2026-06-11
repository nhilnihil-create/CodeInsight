#include <iostream>
#include <vector>
using namespace std;
bool good(int i)
{
	return (i%2==0 || i%3==0 || i%5==0);
}
int main()
{
	int n;
	scanf("%d",&n);
	if (n<=1003)
	{
		printf("2 3 25");
		for (int i=1;i<=n-3;i++)
		printf(" %d",30*i);
		return 0;
	}
	int sum=0,cnt=0;
	for (int i=1;cnt!=n;i++)
	{
		if (good(i))
		{
			if ((cnt==n-2 && !good(sum+i)) || (cnt==n-1 && (sum+i)%30))
			continue;
			sum=(sum+i)%30;
			printf("%d ",i);
			cnt++;
		}
	}
}