#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> C(N), S(N), M(N);

	for (int i = 0; i < N-1; ++i)
	{
		cin >> C[i] >> S[i] >> M[i];
	}

	vector<int> T(N, 0);
	for (int i = 0; i < N-1; ++i)
	{
		for (int j = i; j < N-1; ++j)
		{
			if (T[i] < S[j])
			{
				T[i] = S[j];
			}
			else
			{
				if ((T[i] - S[j]) % M[j] != 0)
				{
					T[i] += M[j] - (T[i] - S[j]) % M[j];
				}
			}

			T[i] += C[j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << T[i] << endl;
	}

	return 0;
}