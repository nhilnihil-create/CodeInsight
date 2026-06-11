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
	
	auto ans = 1ll;
	if (A + 2 >= B || A + 1 > K)
	{
		ans += K;
	}
	else
	{
		K -= A - 1;
		ans = A + (B - A) * (K / 2);
		if (K % 2 > 0)
		{
			++ans;
		}
	}

	cout << ans << endl;

	return 0;
}