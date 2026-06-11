#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	int digit = n;
	while (digit > 0)
	{
		int temp = digit % 10;
		sum += temp;
		digit /= 10;
	}
	if(n % sum == 0) printf("Yes\n");
	else printf("No\n");
	return 0;
}