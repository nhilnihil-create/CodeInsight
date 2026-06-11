#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	vector<ll> A(N);
	auto sum = 0ll;
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
		sum += A[i];
	}
	vector<ll> B(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> B[i];
		sum -= B[i];
	}

	auto result = -1;
	if (sum >= 0)
	{
		result = 0;
		vector<ll> diff(N);
		auto num = 0ll;
		for (auto i = 0; i < N; ++i)
		{
			diff[i] = A[i] - B[i];
			if (diff[i] < 0)
			{
				num += diff[i];
				++result;
			}
		}

		sort(diff.begin(), diff.end(), greater<ll>());

		for (auto i = 0; i < N && num < 0; ++i)
		{
			num += diff[i];
			++result;
		}
	}

	cout << result << endl;

	return 0;
}