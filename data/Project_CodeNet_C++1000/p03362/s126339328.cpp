#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

bool func_prime(int i, int N)
{
	if (i % 5 == 1)
	{
		cout << i;
		cnt++;
		if (cnt == N)
		{
			return true;
		}
		cout << " ";
	}
	return false;
}
int main()
{
	//cin.tie(0);
	//ios::sync_with_stdio(false);
	int N;
	scanf("%d", &N);

	vector<bool> is_prime(55555 + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	int i;
	for (i = 2; i * i <= 55555; i++)
	{
		if (is_prime[i])
		{
			if (func_prime(i, N))
			{
				return 0;
			}

			for (int j = 2; j * i <= 55555; j++)
			{
				is_prime[i * j] = false;
			}
		}
	}
	// cout << " check prime done \n";
	while (i <= 55555)
	{
		if (is_prime[i] && func_prime(i, N))
		{
			return 0;
		}
		i++;
	}
	cout << "failed";
	return 0;
}