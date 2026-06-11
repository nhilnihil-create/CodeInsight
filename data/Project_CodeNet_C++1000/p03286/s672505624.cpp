#include <bits/stdc++.h>
using namespace std;

int main()
{
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	long long N;
	scanf("%lld", &N);

	if (N == 0)
	{
		cout << 0;
		return 0;
	}
	long long keta = 1;
	vector<long long> result = {};
	while (N != 0)
	{
		if (N % (keta * 2) != 0)
		{
			N -= keta;
			// cout << N << "\n";
			result.push_back(1);
		}
		else
		{
			result.push_back(0);
		}
		keta *= -2;
	}

	for (long long i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i];
	}

	return 0;
}