#include <iostream>
#include <queue>
#include <tuple>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;

	vector<int64_t> A(X+1);
	vector<int64_t> B(Y+1);
	vector<int64_t> C(Z+1);

	for (int i = 0; i < X; ++i)
	{
		cin >> A[i];
	}
	A[X] = -100000000000;

	for (int i = 0; i < Y; ++i)
	{
		cin >> B[i];
	}
	B[Y] = -100000000000;

	for (int i = 0; i < Z; ++i)
	{
		cin >> C[i];
	}
	C[Z] = -100000000000;

	sort(A.begin(), A.end(), std::greater<int64_t>());
	sort(B.begin(), B.end(), std::greater<int64_t>());
	sort(C.begin(), C.end(), std::greater<int64_t>());

	using elem = tuple<int64_t, int, int, int>;

	auto compare = [](elem a, elem b) {
		return get<0>(a) < get<0>(b);
	};

	priority_queue<elem, vector<elem>, decltype(compare)> que(compare);
	set<elem> checker;
	elem first_elem = make_tuple(A[0] + B[0] + C[0], 0, 0, 0);

	que.push(first_elem);
	checker.insert(first_elem);
	for (int i = 0; i < K; ++i)
	{
		elem top_elem = que.top();
		
		int64_t sum = get<0>(top_elem);
		int l = get<1>(top_elem);
		int m = get<2>(top_elem);
		int n = get<3>(top_elem);

		cout << sum << endl;
		elem candidate[3] =
		{ make_tuple(A[l+1] + B[m] + C[n], l+1, m, n)
		, make_tuple(A[l] + B[m+1] + C[n], l, m+1, n)
		, make_tuple(A[l] + B[m] + C[n+1], l, m, n+1) };

		que.pop();

		for (int j = 0; j < 3; ++j)
		{
			if (checker.find(candidate[j]) == checker.end())
			{
				checker.insert(candidate[j]);
				que.push(candidate[j]);
			}
		}
	}

	return 0;
}