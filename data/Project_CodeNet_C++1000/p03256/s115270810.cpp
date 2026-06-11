#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <deque>

using namespace::std;

int ri()
{
	int x;
	scanf("%d", &x);

	return x;
}

int64_t ri64()
{
	int64_t x;
	scanf("%lld", &x);

	return x;
}

void wi(int x)
{
	printf("%d\n", x);
}

void wvi(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
}

void dbg(string &str, int x)
{
	cout << str << ": ";
	wi(x);
}

void dbg(string &str, vector<int> &x)
{
	cout << str << ": ";
	wvi(x);
}

int main()
{
	string yes = "Yes";
	string no = "No";

	int N = ri();
	int M = ri();

	string str;
	cin >> str;

	vector<vector<int> > adj(N, vector<int>());
	vector<int> nb(N, 0);
	vector<int> nw(N, 0);

	for (int i = 0; i < M; i++)
	{
		int x = ri() - 1;
		int y = ri() - 1;

		adj[x].push_back(y);
		adj[y].push_back(x);

		if (str[x] == 'B')
			nb[y]++;
		else
			nw[y]++;

		if (str[y] == 'B')
			nb[x]++;
		else
			nw[x]++;
	}

	vector<bool> dead(N, false);

	queue<int> q;
	for (int i = 0; i < N; i++)
		if (nb[i] == 0 || nw[i] == 0)
		{
			dead[i] = true;
			q.push(i);
		}

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < adj[x].size(); i++)
		{
			int y = adj[x][i];
			if (dead[y])
				continue;

			if (str[x] == 'B')
				nb[y]--;
			else
				nw[y]--;

			if (nb[y] == 0 || nw[y] == 0)
			{
				dead[y] = true;
				q.push(y);
			}
		}
	}

	bool ok = false;
	for (int i = 0; i < N; i++)
		if (!dead[i])
			ok = true;

	if (ok)
		cout << yes << endl;
	else
		cout << no << endl;

	return 0;
}
