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

void getPrime(int n, vector<int>& list)
{
	vector<bool> isPrime(n + 1, true);

	for (auto i = 2; i <= n; ++i)
	{
		if (isPrime[i])
		{
			list.push_back(i);
			for (auto j = 2; (ll)i * j <= n; ++j)
			{
				isPrime[i * j] = false;
			}
		}
	}
}


int main()
{
	int N;
	cin >> N;

	vector<int> list;
	getPrime(55555, list);
	auto num = 0;
	for (auto i = 0; i < (int)list.size(); ++i)
	{
		if (list[i] % 10 == 1)
		{
			if (num > 0)
			{
				cout << " ";
			}
			cout << list[i];
			++num;
			if (num >= N)
			{
				break;
			}
		}
	}
	cout << endl;
	
	return 0;
}