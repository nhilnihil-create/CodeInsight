#include <iostream>
#include <vector>
#include <map>
using namespace std;

constexpr int MaxN = 100000;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int64_t> A(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	vector<int64_t> B(N);
	B[0] = A[0];
	for (int i = 1; i < N; ++i)
	{
		B[i] = A[i] + B[i-1];
	}

	map<int64_t, int64_t> num;
	for (int i = 0; i < N; ++i)
	{
		++num[B[i] % M];
	}

	int64_t sum = 0;
	for (auto n : num)
	{
		if (n.first == 0)
		{
			sum += n.second;
		}
		sum += n.second * (n.second - 1) / 2;
	}

	cout << sum << endl;

	return 0;
}