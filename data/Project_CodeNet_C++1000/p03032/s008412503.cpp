#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int N, K;
	cin >> N >> K;

	vector<int> V(N);
	for (int i = 0; i < N; i++)
		cin >> V[i];

	int ans = 0;
	for (int l = 0; l <= K; l++)
	{
		for (int r = 0; r <= K-l; r++)
		{
			if (l + r > N)
				break ;

			int sum = 0;
			vector<int> S;
			for (int i = 0; i < l; i++)
			{
				sum += V[i];
				S.push_back(V[i]);
			}
			for (int i = N-1; i > N-1-r; i--)
			{
				sum += V[i];
				S.push_back(V[i]);
			}
			sort(all(S));

			int d = K - (l+r);
			for (int i = 0; i < min(d, (int)S.size()); i++)
			{
				if (S[i] < 0)
					sum -= S[i];
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}

