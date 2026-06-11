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
	ll sum = 0;
	vector<ll> minus;
	for (auto i = 0; i < N; ++i)
	{
		ll A, B;
		cin >> A >> B;
		sum += A;
		minus.push_back(-A - B);
	}

	sort(minus.begin(), minus.end());
	for (auto i = 1; i < N; i += 2)
	{
		sum += minus[i];
	}
	cout << sum << endl;

	return 0;
}