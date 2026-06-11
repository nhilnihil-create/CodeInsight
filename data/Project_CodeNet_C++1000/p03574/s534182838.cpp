#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char c[55][55];
int num[55][55];

int main()
{
	int H,W;
	cin >> H >> W;
	rep(i,H)
	{
		rep(j,W)
		{
			cin >> c[i][j];
		}
	}

	rep(i,H)
	{
		rep(j,W)
		{
			if (c[i][j] == '.')
			{
				int cnt = 0;
				for (int k = -1; k <= 1; ++k)
				{
					for (int l = -1; l <= 1; ++l)
					{
						if (k != 0 || l != 0)
						{
							if (i+k >= 0 && i+k < H && j+l >= 0 && j+l < W && c[i+k][j+l] == '#')
							{
								cnt++;
							}
						}
					}
				}
				num[i][j] = cnt;
			}
		}
	}

	rep(i,H)
	{
		rep(j,W)
		{
			if (c[i][j] == '.') cout << num[i][j];
			else cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}