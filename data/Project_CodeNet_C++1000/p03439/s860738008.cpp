#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int N; cin >> N;
	cout << 0 << endl;
	string s; cin >> s;
	if (s == "Vacant") return 0;
	bool evenIsMale = s == "Male";
	int low = 0, high = N;
	for (;;)
	{
		int mid = (low + high) / 2;
		cout << mid << endl;
		cin >> s; if (s == "Vacant") break;
		if (mid % 2 == 0)
		{
			if (evenIsMale && s == "Male")
			{
				low = mid;
			}
			else if (!evenIsMale && s == "Female")
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
		}
		else
		{
			if (evenIsMale && s == "Female")
			{
				low = mid;
			}
			else if (!evenIsMale && s == "Male")
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
		}
	}
}
