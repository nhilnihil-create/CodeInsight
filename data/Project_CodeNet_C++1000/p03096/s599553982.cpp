#include <iostream>
#include <vector>
#define N 200010
#define mod 1000000007
using namespace std;
int ans[N],stone[N];
int n;
int a[N];
int main()
{
	cin >> n;
	int sum = 1;
	for(int i = 1;i <=  n;i ++)
	{
		scanf("%d",stone + sum);
		if(stone[sum] ^ stone[sum - 1])
			sum ++;
	}
	sum --;
	ans[1] = 1;
	a[stone[1]] = 1;
	for(int i = 2;i <= sum;i ++)
	{
		int now_color = stone[i];
		ans[i] = (ans[i - 1] + ans[a[now_color]]) % mod;
		a[now_color] = i;
	}
	printf("%d\n",ans[sum]);
	return 0;
}