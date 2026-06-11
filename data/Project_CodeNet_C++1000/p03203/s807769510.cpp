#include "bits/stdc++.h"

using namespace std;

void solve()
{
	long H, W, N;
	cin >> H >> W >> N;
	vector<long> walls[W];
	map<long, bool> iswall;
	while (N--)
	{
		long h, w;
		cin >> h >> w;
		walls[w-1].push_back(h-1);
		iswall[W*(h-1)+w-1] = 1;
	}

	for (long w = 0; w < W; w++)
	{
		walls[w].push_back(H);
		iswall[H*W+w] = 1;
		sort(walls[w].begin(), walls[w].end());
	}

	long ans = *lower_bound(walls[0].begin(), walls[0].end(), 0);
	long nh = 0, nw = 0;

	while (nw < W-2)
	{
		bool f = 0;

		while(!iswall[(nh+1)*W+nw])
		{
			f = 1;
			nh++;
			if (!iswall[nh*W+nw+1])
			{
				nw++;
				break;
			}
		}

		if (!f) break;

		ans = min(*lower_bound(walls[nw].begin(), walls[nw].end(), nh), ans);

		//cout << nw << ' ' << nh << ' ' << ans << endl;
	}

	cout << ans << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
