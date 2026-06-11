#include<bits/stdc++.h>
using namespace std;


int sum_of_digits(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num%10;
		num /= 10;
	}
	return sum;
}

int main()
{
	int n,a,b; cin >>n>>a>>b;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x = sum_of_digits(i);
		if (a <= x && x <= b)
			ans += i;
	}
	cout << ans << endl;
}

