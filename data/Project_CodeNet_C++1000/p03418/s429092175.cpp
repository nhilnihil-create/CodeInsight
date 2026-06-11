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
	int N, K;
	cin >> N >> K;

	auto ans = 0ll;
	for (auto b = K + 1; b <= N; ++b)
	{
		ans += N / b * (b - K);
		if (K > 0)
		{
			ans += max(0, N % b - K + 1);
		}
		else
		{
			ans += N % b;
		}
	}
	cout << ans << endl;

	return 0;
}