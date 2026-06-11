#include<bits/stdc++.h>
using namespace std;

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

int main() {
	int h, w; cin >> h >> w;
	string s[h];
	for (int i = 0; i < h; i++)	cin >> s[i];
	int res[h][w] = {};
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 8; k++)
			{
				if(i + dy[k] < 0 || i + dy[k] >= h || j + dx[k] < 0 || j + dx[k] >= w) continue;
				if(s[i+dy[k]][j+dx[k]] == '#') cnt++;
			}
			res[i][j] = cnt;
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if(s[i][j] == '#') cout << "#";
			else cout << res[i][j];
		}
		cout << endl;
	}

	return 0;
}
