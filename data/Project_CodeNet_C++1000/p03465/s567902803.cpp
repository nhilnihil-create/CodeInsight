#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N;
	cin >> N;
	int	A[2000];
	int	sum_A = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		sum_A += A[i];
	}
	bitset<4000000>	dp(1);
	for (int i = 0; i < N; ++i)
		dp |= (dp << A[i]);
	for (int i = (sum_A + 1) / 2; i <= sum_A; ++i) {
		if (dp.test(i)) {
			cout << i << endl;
			break;
		}
	}
}
