#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	vector<string> mat;
	for (auto i = 0; i < 100; ++i)
	{
		if (i < 50)
		{
			mat.push_back(string(100, '.'));
		}
		else
		{
			mat.push_back(string(100, '#'));
		}
	}

	for (auto i = 0; i < 50; i += 2)
	{
		if (B - 1 <= 0)
		{
			break;
		}

		for (auto j = 0; j < 100; j += 2)
		{
			mat[i][j] = '#';
			--B;
			if (B - 1 <= 0)
			{
				break;
			}
		}
	}


	for (auto i = 0; i < 50; i += 2)
	{
		if (A - 1 <= 0)
		{
			break;
		}

		for (auto j = 0; j < 100; j += 2)
		{
			mat[99 - i][j] = '.';
			--A;
			if (A - 1 <= 0)
			{
				break;
			}
		}
	}

	cout << 100 << " " << 100 << endl;
	for (auto i = 0; i < 100; ++i)
	{
		cout << mat[i] << endl;
	}

	return 0;
}
