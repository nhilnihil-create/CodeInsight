#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n, q;
	cin >> n >> q;
	string S;
	cin >> S;

	vector<int> AC(100100);
	int cnt = 0;
	for (int i = 0; i < n-1; ++i)
	{
		if (S[i] == 'A' && S[i+1] == 'C')
			++cnt;
		AC[i+1] = cnt;
	}

	vector<int> ans(q);
	for (int i = 0; i < q; ++i)
	{
		int L, R;
		cin >> L >> R;
		ans[i] = AC[R-1] - AC[L-1];
	}
	for (int i = 0; i < q; ++i)
		cout << ans[i] << endl;
}

