#include <bits/stdc++.h>
using namespace std;

int	sum_digits(int num)
{
	int	sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int	main()
{
	int	N;
	cin >> N;
	int	min_sum = 100;
	int	cur_sum;
	for (int a = 1; a < N; ++a) {
		cur_sum = sum_digits(a) + sum_digits(N - a);
		if (cur_sum < min_sum) min_sum = cur_sum;
	}
	cout << min_sum << endl;
}
