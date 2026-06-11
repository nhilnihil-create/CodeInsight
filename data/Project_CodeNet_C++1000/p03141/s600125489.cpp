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
	ll N;
	cin >> N;
	vector<pair<ll, ll>> d;
	vector<ll> A(N);
	vector<ll> B(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i] >> B[i];
		auto sum = A[i] + B[i];
		d.push_back({ abs(sum), i });
	}

	auto sum = 0ll;
	sort(d.begin(), d.end(), greater<pair<ll, ll>>());
	for (auto i = 0; i < N; ++i)
	{
		auto& p = d[i];
		if (i % 2 == 0)
		{
			sum += A[p.second];
		}
		else
		{
			sum -= B[p.second];
		}
	}

	cout << sum << endl;

	return 0;
}