#include <bits/stdc++.h>
using namespace std;

int func(long long n, bool f3, bool f5, bool f7, int N, long long *presult)
{
	if (n > N)
	{
		// cout << n << ":"
		// 	 << "0"
		// 	 << "\n";
		return 0;
	}
	else
	{
		if (f3 && f5 && f7)
		{
			(*presult)++;
		}
		func(n * 10 + 3, true, f5, f7, N, presult);
		func(n * 10 + 5, f3, true, f7, N, presult);
		func(n * 10 + 7, f3, f5, true, N, presult);
		// cout << n << ":" << ret << "\n";
		return 0;
	}
}

int main()
{
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	long long N;
	scanf("%lld", &N);
	long long result = 0;
	func(0, false, false, false, N, &result);
	cout << result;
	return 0;
}