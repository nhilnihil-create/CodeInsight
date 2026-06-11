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
	vector<ll> diff;
	for (auto i = 0; i < N; ++i)
	{
		ll A;
		cin >> A;
		diff.push_back(A);
	}
	for (auto i = 0; i < N; ++i)
	{
		ll B;
		cin >> B;
		diff[i] -= B;
	}

	sort(diff.begin(), diff.end());
	auto minus = 0ll;
	auto ans = 0;
	for (auto i = 0; i < N && diff[i] < 0; ++i)
	{
		minus += diff[i];
		++ans;
	}

	for (auto i = N - 1; i >= 0 && diff[i] > 0; --i)
	{
		if (minus >= 0)
		{
			break;
		}
		minus += diff[i];
		++ans;
	}

	if (minus < 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}


	return 0;
}