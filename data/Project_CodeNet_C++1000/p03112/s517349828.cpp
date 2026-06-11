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
	int A, B, Q;
	cin >> A >> B >> Q;
	vector<ll> s(A + 2);
	vector<ll> t(B + 2);
	for (auto i = 0; i < A; ++i)
	{
		cin >> s[i + 1];
	}
	for (auto i = 0; i < B; ++i)
	{
		cin >> t[i + 1];
	}
	s[0] = LLONG_MIN / 3;
	s[A + 1] = LLONG_MAX / 3;
	t[0] = LLONG_MIN / 3;
	t[B + 1] = LLONG_MAX / 3;

	vector<ll> ans;
	for (auto i = 0; i < Q; ++i)
	{
		ll x;
		cin >> x;

		auto its = upper_bound(s.begin(), s.end(), x);
		auto itt = upper_bound(t.begin(), t.end(), x);

		auto temp = max(*its, *itt) - x;
		auto res = temp;

		temp = *its - *(itt - 1) + min(*its - x, x - *(itt - 1));
		res = min(res, temp);

		temp = *itt - *(its - 1) + min(*itt - x, x - *(its - 1));
		res = min(res, temp);

		temp = x - min(*(its - 1), *(itt - 1));
		res = min(res, temp);

		ans.push_back(res);
	}

	for (auto a : ans)
	{
		cout << a << endl;
	}

	return 0;
}