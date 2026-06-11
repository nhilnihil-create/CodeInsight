#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void ABC118D()
{
	vector<int> X = { 0,2,5,5,4,5,6,3,7,6 };
	int N, M;
	cin >> N >> M;
	vector<int> A(M);
	for (auto& x : A)
		cin >> x;
	map<int, int> mmap;
	for (int i = 0; i < M; ++i)
		mmap[A[i]] = X[A[i]];
	vector<int> B;
	for (int i = M - 1; i > -1; --i)
	{
		B.push_back(X[A[i]]);
	}
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());

	vector<int> dp(N + 10,-1);
	dp[0] = 0;
	for (int i = 0; i < B.size(); ++i)
		dp[B[i]] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < B.size(); ++j)
		{
			dp[i + B[j]] = max(dp[i + B[j]], dp[i] + 1);
		}
	}

	int dec = dp[N];
	int n = N;
	vector<int> ret(dec);
	for (int i = 0; i < dec; ++i)
	{
		for (auto p = mmap.rbegin(); p != mmap.rend(); ++p)
		{
			int y = p->second;
			if ((dp[n] == 1 && n-y == 0)|| (n >= y && dp[n - y] == dp[n] - 1))
			{
				ret[i] = p->first;
				n -= y;
				break;
			}
		}
	}
	ll x = 0;
	for (int i = 0; i < dec; ++i)
	{
		cout << ret[i];
		/*x *= 10;
		x += ret[i];*/
	}
//	cout << x << endl;
	cout << endl;
}
int main()
{
	ABC118D();
	return 0;
}