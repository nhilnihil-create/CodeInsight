#include <iostream>
#include <cstring>
#include <utility>
#include <array>
using namespace std;

constexpr int MaxN = 500;

int main()
{
	int N, M, Q;

	cin >> N >> M >> Q;

	int C[MaxN][MaxN];
	memset(C, 0, MaxN * MaxN * sizeof(int));

	for (int i = 0; i < M; ++i)
	{
		int L, R;
		cin >> L >> R;
		++C[L-1][R-1];
	}

	for (int i = 1; i < N; ++i)
	{
		C[i][0] += C[i-1][0];
		C[0][i] += C[0][i-1];
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			C[i][j] += C[i-1][j] + C[i][j-1] - C[i-1][j-1];
		}
	}

	for (int i = 0; i < Q; ++i)
	{
		int p, q;
		cin >> p >> q;
		--p;
		--q;

		int count = C[q][q];

		if (p > 0)
		{
			count -= C[p-1][q];
			count -= C[q][p-1];
			count += C[p-1][p-1];
		}

		cout << count << endl;
	}

	return 0;
}