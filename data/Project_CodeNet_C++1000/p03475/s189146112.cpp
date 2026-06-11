#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n;
	cin >> n;

	vector<int> C(510);
	vector<int> S(510);
	vector<int> F(510);
	for (int i = 0; i < n-1; ++i)
		cin >> C[i] >> S[i] >> F[i];

	for (int i = 0; i < n; ++i)
	{
		int ans = S[i] + C[i];
		for (int j = i+1; j < n-1; ++j)
		{
			if (ans < S[j])
				ans += S[j] - ans;
			else if (ans > S[j])
			{
				int t = S[j];
				// 爆発？
				while (ans > t)
				  t += F[j];
				ans += t - ans;
			}
			ans += C[j];
		}
		cout << ans << endl;
	}
}

