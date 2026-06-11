#include <stdio.h>
#include <string.h>
#include <deque>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#define lp(i, b) for(int i = 0; i < b; ++i) 
using namespace std;
bool is_prime(int k)
{
	if (k == 1) return false;
	if (k % 2 == 0) return k == 2;
	for (int i = 3; i * i <= k; i += 2)
	{
		if (k % i == 0) return false;
	}
	return true;
}
int main()
{
	vector<int> prime2017(pow(10, 5), 0);
	int n = 0;
	function<bool(int)> judge = [&](int x)
	{
		if (is_prime(x) && is_prime((x + 1) / 2))
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