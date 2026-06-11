#include<bits/stdc++.h>
using namespace std;


int sum_of_digits(int n)
{
	int sum = 0;
	while(n > 0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int n; cin >> n;
	int minval = 1e9;
	for(int i = 1; i < n; ++i)
	{
		int x = sum_of_digits(i) + sum_of_digits(n-i);
		minval = min(minval, x);
	}
	cout << minval << endl;
}

