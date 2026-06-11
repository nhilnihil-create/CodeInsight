#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200010;
int a[N];
int n, s;

int main()
{
	int n;
	long long res = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	int j = 0;
	long long tmp = 0, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		while(j + 1 <= n && (tmp ^ a[j + 1]) == sum + a[j + 1])
		//找到最右边满足条件的右端点 
		{
			sum += a[j + 1];
			tmp ^= a[j + 1];
			j++;
		}
		if(tmp == sum)
			res += j - i + 1;
		sum -= a[i];
		tmp ^= a[i];
	}
	printf("%lld\n",res);
	return 0;
}
