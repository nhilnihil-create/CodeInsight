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

ll func(ll n)
{
	auto temp = (n + 1) / 2 % 2;
	if (n % 2 == 0)
	{
		temp ^= n;
	}

	return temp;
}

int main()
{
	ll A, B;
	cin >> A >> B;

	cout << (func(A - 1) ^ func(B)) << endl;

	return 0;
}