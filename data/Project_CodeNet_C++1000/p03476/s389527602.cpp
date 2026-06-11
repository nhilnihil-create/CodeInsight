#include <stdio.h>
#include <iostream>
#include <functional>
#include <vector>
#define lp(i, b) for(int i = 0; i < b; ++i) 
using namespace std;
void init_is_prime(int n, vector<int>& is_prime)
{
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (!is_prime[i]) continue;
		for (int j = i * i; j < n; j += i)
			is_prime[j] = 0;
	}
}
int main()
{
	vector<int> is_prime(pow(10, 5), 1);
	init_is_prime(pow(10, 5), is_prime);
	vector<int> prime2017(pow(10, 5), 0);
	int n = 0;
	function<bool(int)> judge = [&](int x)
	{
		if (is_prime[x] && is_prime[(x + 1) / 2])
		{
			return true;
		}
		return false;
	};
	lp(i, pow(10, 5))
	{
		if (!judge(i)) prime2017[i] = n;
		else
		{
			prime2017[i] = ++n;
		}
	}
	int m;
	int l, r;
	cin >> m;
	lp(i, m)
	{
		cin >> l >> r;
		cout << prime2017[r] - prime2017[l - 1] << endl;
	}
}