#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_HW = 55;
char s[MAX_HW][MAX_HW];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int main()
{
	int H,W;
	cin >> H >> W;
	rep(i,H)
	{
		rep(j,W)
		{
			cin >> s[i][j];
		}
	}

	rep(i,H)
	{
		rep(j,W)
		{
			if (s[i][j] == '.') continue;
			bool flag = false;
			rep(k,4)
			{
				int ii = i + dx[k], jj = j + dy[k];
				if (ii >= 0 && ii < H && jj >= 0 && jj < W && s[ii][jj] == '#') flag = true;
			}
			if (!flag)
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}