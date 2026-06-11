#include <bits/stdc++.h>
using namespace std;

int main()
{
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	int H, W, D;
	scanf("%d %d %d", &H, &W, &D);

	vector<vector<int>> from_i(D, vector<int>(((H * W) / D) + 1, -1));
	vector<vector<pair<int, int>>> loc(D, vector<pair<int, int>>(((H * W) / D) + 1, make_pair(-1, -1)));
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			tmp--; //0~H*W-1
			loc[tmp % D][tmp / D] = make_pair(i, j);
		}
	}

	for (int i = 0; i < D; i++)
	{
		from_i[i][0] = abs(loc[i][0].first - 0) + abs(loc[i][0].second - 0);
		// cout << i << "\n"
		// 	 << from_i[i][0] << " ";
		for (int j = 1; j < ((H * W) / D) + 1; j++)
		{
			if (loc[i][j].first == -1)
			{
				break;
			}
			from_i[i][j] = from_i[i][j - 1] + abs(loc[i][j].first - loc[i][j - 1].first) + abs(loc[i][j].second - loc[i][j - 1].second);
			// cout << from_i[i][j] << " ";
		}
		// cout << "\n";
	}

	int Q;
	scanf("%d", &Q);

	for(int i=0;i<Q;i++){
		int L,R;
		scanf("%d %d", &L, &R);
		L--;
		R--;
		printf("%d\n",from_i[R%D][R/D]-from_i[L%D][L/D]);
	}
	return 0;
}