#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define x first
#define y second

const int N = 2e3 + 10;
const ll mod = 1e9 + 7;


int n, k, q, a[N];
int used[N];
int ans = 1e9;
set < int > s;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifdef KEK
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> k >> q;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int u : s)
	{
		for (int i = 1; i <= n; ++i) used[i] = 0;
		for (int i = 1; i <= n; ++i) if (a[i] < u) used[i] = 1;
		vector < int > cur, ae;
		//cout << u << endl;
		used[n + 1] = 1;
		for (int i = 1; i <= n + 1; ++i)
		{
			if (!used[i]) cur.push_back(a[i]);
			else 
			{
				if (cur.size() == 0) continue;
				
				sort(cur.begin(), cur.end());
				for (int j = 0 ; j < (int)cur.size() - k + 1; ++j) ae.push_back(cur[j]);
				cur.clear();
			}
		}

		sort(ae.begin(), ae.end());
		if (ae.size() < q) continue;
		ans = min(ae[q - 1] - u, ans);
	}
	cout << ans;
	
	return 0;	
}