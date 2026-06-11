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
	vector<int> temp(N);
	for (auto i = 0; i < N; ++i)
	{
		auto P = 0;
		cin >> P;
		temp[P - 1] = i;
	}

	auto result = 0;
	for (auto i = 0; i < N;)
	{
		auto j = i + 1;
		for (; j < N && temp[j] > temp[j - 1]; ++j);
		result = max(result, j - i);
		i = j;
	}

	cout << N - result << endl;

	return 0;
}