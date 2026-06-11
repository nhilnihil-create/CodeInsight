#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> S(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	bool isValid[601];
	for (auto i = -N + 1; i < N; ++i)
	{
		isValid[i + N - 1] = true;
		for (auto j = 0; j < N; ++j)
		{
			for (auto k = 0; k < N; ++k)
			{
				auto compOffset = -j + k + i;
				auto compX = (j + compOffset + N) % N;
				auto compY = (k - compOffset + N) % N;
				if (S[k][j] != S[compY][compX])
				{
					isValid[i + N - 1] = false;
				}
			}
		}
	}

	auto result = 0;
	for (auto A = 0; A < N; ++A)
	{
		for (auto B = 0; B < N; ++B)
		{
			if (isValid[-B + A + N - 1])
			{
				++result;
			}
		}
	}
	cout << result << endl;

	return 0;
}