#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool edge[5][5];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int a, b;

	memset(edge, false, sizeof(edge));
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b;
		edge[a][b] = true;
		edge[b][a] = true;
	}

	vector <int> perm = { 1,2,3,4 };

	do
	{
		bool ok = true;
		for (int i = 1; i < perm.size(); i++)
		{
			if (edge[perm[i - 1]][perm[i]]==false)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			cout << "YES" << '\n';
			return 0;
		}
	} while (next_permutation(perm.begin(), perm.end()));
	
	cout << "NO" << '\n';
	return 0;
}