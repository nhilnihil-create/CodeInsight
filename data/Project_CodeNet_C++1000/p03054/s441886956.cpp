#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <iomanip>
#include <unordered_map>
#include <memory.h>
#include <cstring>
#include <fstream>

using namespace std;

int h, w, n;
int sy, sx;
string s;
string t;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> h >> w >> n;
	cin >> sy >> sx;
	cin >> s;
	cin >> t;

	int y = sy;
	int x = sx;
	for (int i = 0; i < n; i++)
	{
		//cout << y << ' ' << x << '\n';
		if (s[i] == 'L')
		{
			x -= 1;
			if (x <= 0)
			{
				cout << "NO" << '\n';
				return 0;
			}
		}
		if (t[i] == 'R')
		{
			if (x + 1 <= w)
			{
				x += 1;
			}
		}
	}

	y = sy;
	x = sx;
	for (int i = 0; i < n; i++)
	{
		//cout << y << ' ' << x << '\n';
		if (s[i] == 'R')
		{
			x += 1;
			if (x > w)
			{
				cout << "NO" << '\n';
				return 0;
			}
		}
		if (t[i] == 'L')
		{
			if (x - 1 > 0)
			{
				x -= 1;
			}
		}
	}

	y = sy;
	x = sx;
	for (int i = 0; i < n; i++)
	{
		//cout << y << ' ' << x << '\n';
		if (s[i] == 'U')
		{
			y -= 1;
			if (y <= 0)
			{
				cout << "NO" << '\n';
				return 0;
			}
		}
		if (t[i] == 'D')
		{
			if (y + 1 <= h)
			{
				y += 1;
			}
		}
	}

	y = sy;
	x = sx;
	for (int i = 0; i < n; i++)
	{
		//cout << y << ' ' << x << '\n';
		if (s[i] == 'D')
		{
			y += 1;
			if (y > h)
			{
				cout << "NO" << '\n';
				return 0;
			}
		}
		if (t[i] == 'U')
		{
			if (y - 1 > 0)
			{
				y -= 1;
			}
		}
	}

	cout << "YES" << '\n';

	return 0;
}