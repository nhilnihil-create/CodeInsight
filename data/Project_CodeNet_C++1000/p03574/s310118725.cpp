#include<bits/stdc++.h>
using namespace std;


int main()
{
	int h, w;
	char c = 48;
	cin >> h >> w;
	char masu[h][w];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> masu[i][j];
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (masu[i][j] == '.')	
			{
				for (int y = -1; y < 2; y++)
					for (int x = -1; x < 2; x++)
						if (i+y >=0 && i+y < h && j+x >= 0 && j+x < w)
							if (masu[i+y][j+x] == '#')
								c++;
				masu[i][j] = c;
				c = 48;
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << masu[i][j];
		cout << endl;
	}
}

