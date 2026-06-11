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
	int K;
	cin >> K;
	vector<long long> A(K);
	for (auto i = 0; i < K; ++i)
	{
		cin >> A[i];
	}

	auto minV = 2ll;
	auto maxV = 3ll;
	auto isValid = true;
	if (A[K - 1] != 2)
	{
		isValid = false;
	}
	else
	{
		for (auto i = K - 2; i >= 0; --i)
		{
			auto v = A[i];
			if (v < minV && (minV % v) != 0 && (minV / v + 1) * v > maxV)
			{
				isValid = false;
				break;
			}
			else if (v > maxV)
			{
				isValid = false;
				break;
			}

			maxV = (maxV / v + 1) * v - 1;
			if (minV % v != 0)
			{
				minV = (minV / v + 1) * v;
			}
		}
	}

	if (!isValid)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << minV << " " << maxV << endl;
	}

	return 0;
}