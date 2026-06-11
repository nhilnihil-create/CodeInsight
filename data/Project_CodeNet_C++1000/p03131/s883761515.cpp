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
	ll K, A, B;
	cin >> K >> A >> B;

	auto ans = 0ll;
	if (A + 2 < B && K >= A + 1)
	{
		ans = A;
		K -= A - 1;
		ans += (K / 2) * (B - A);
		if (K % 2 > 0)
		{
			++ans;
		}
	}
	else
	{
		ans = K + 1;
	}

	cout << ans << endl;

	return 0;
}