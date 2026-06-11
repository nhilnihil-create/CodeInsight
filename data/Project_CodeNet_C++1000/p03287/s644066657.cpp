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
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	map<ll, ll> m;
	auto prev = 0ll;
	for (auto i = 0; i < N; ++i)
	{
		auto next = (prev + A[i]) % M;
		++m[next];
		prev = next;
	}
	++m[0];

	auto ans = 0ll;
	for (auto p : m)
	{
		ans += p.second * (p.second - 1) / 2;
	}
	cout << ans << endl;

	return 0;
}