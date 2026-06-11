#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<vector<int>> a(H, vector<int>(W));
	for (auto i = 0; i < H; ++i)
	{
		for (auto j = 0; j < W; ++j)
		{
			cin >> a[i][j];
		}
	}
	
	vector<int> prevY;
	vector<int> prevX;
	vector<int> nextY;
	vector<int> nextX;
	for (auto i = 0; i < H; ++i)
	{
		for (auto j = 0; j < W; ++j)
		{
			auto currentJ = j;
			if (i % 2 > 0)
			{
				currentJ = W - j - 1;
			}

			if (a[i][currentJ] % 2 == 0)
			{
				continue;
			}

			if (i >= H - 1 && j >= W - 1)
			{
				continue;
			}

			prevY.push_back(i + 1);
			prevX.push_back(currentJ + 1);

			auto ny = i;
			auto nx = currentJ;
			if (j >= W - 1)
			{
				++ny;
			}
			else if(i % 2 == 0)
			{
				++nx;
			}
			else
			{
				--nx;
			}
			nextY.push_back(ny + 1);
			nextX.push_back(nx + 1);
			++a[ny][nx];
		}
	}

	cout << (int)prevY.size() << endl;
	for (auto i = 0; i < (int)prevY.size(); ++i)
	{
		cout << prevY[i] << " " << prevX[i] << " " << nextY[i] << " " << nextX[i] << endl;
	}

	return 0;
}